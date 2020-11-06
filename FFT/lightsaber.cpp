#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 200010
#define MOD 1009
#define MAXL 30
#define ROOT 1
#define INF 987654321
#define PI acos(-1)

namespace FFT {
	using cd = complex<double>;
    void fft(vector<cd> &a, int logN, int sign) {
        for (int i = 0; i < a.size(); i++) {
            int mask = 0;
            for (int j = 0; j < logN; j++) {
                if (i >> j & 1) mask |= (1 << logN - j - 1);
            }
            if (i < mask) swap(a[i], a[mask]);
        }
 
        for (int k = 1; k < a.size(); k <<= 1) {
            cd wDelta = polar(1.0, PI * sign / k);
            cd w(1, 0);
            for (int i = 0; i < k; i++, w *= wDelta) {
                for (int j = i; j < a.size(); j += k * 2) {
                    cd foo = a[j];
                    cd bar = w * a[j + k];
                    a[j] = foo + bar;
                    a[j + k] = foo - bar;
                }
            }
        }
    }
 
    vector<long long> multiply(vector<long long> &a, vector<long long> &b) {
        int sz = a.size() + b.size() - 1;
        int logN = 0;
        while ((1 << logN) < sz) logN++;

        vector<cd> aa(1 << logN, 0), bb(1 << logN, 0);

        for (int i = 0; i < a.size(); i++) aa[i] = a[i];
        for (int i = 0; i < b.size(); i++) bb[i] = b[i];

        fft(aa, logN, 1);
        fft(bb, logN, 1);

        for (int i = 0; i < aa.size(); i++) {
            aa[i] *= bb[i];
        }

        fft(aa, logN, -1);
        vector<long long> res(sz);
        for (int i = 0; i < sz; i++) {
            res[i] = (long long)(aa[i].real() / (1 << logN) + 0.5);
        }
        return res;
    }
};

vector<ll> v[MAXN];
ll n, m, k;

void read(){
	cin >> n >> m >> k;
	frr(i, m) v[i].pb(1);
	frr(i, n){
		ll a;
		cin >> a;
		v[a].pb(1);
	}
}

vector<ll> solve(ll l, ll r){
	if(l == r) return v[l];

	ll mid = (l + r)/2;
	vector<ll> v1 = solve(l, mid), v2 = solve(mid + 1, r);

	v1 = FFT::multiply(v1, v2);
	if(v1.size() > k + 1) 
		v1.resize(k + 1); 

	fr(i, v1.size()) v1[i] = v1[i]%MOD;

	return v1;
}

int main(){
	ios::sync_with_stdio(false);

	read();
	vector<ll> ret = solve(1, m);
	cout << ret[k] << endl;
}
