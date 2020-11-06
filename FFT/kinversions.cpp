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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

namespace FFT {
	using cd = complex<double>;

    #define PI acos(-1)
    void fft(vector<cd> &a, ll logN, ll sign) {
        for (ll i = 0; i < a.size(); i++) {
            ll mask = 0;
            for (ll j = 0; j < logN; j++) {
                if (i >> j & 1) mask |= (1 << logN - j - 1);
            }
            if (i < mask) swap(a[i], a[mask]);
        }
 
        for (ll k = 1; k < a.size(); k <<= 1) {
            cd wDelta = polar(1.0, PI * sign / k);
            cd w(1, 0);
            for (ll i = 0; i < k; i++, w *= wDelta) {
                for (ll j = i; j < a.size(); j += k * 2) {
                    cd foo = a[j];
                    cd bar = w * a[j + k];
                    a[j] = foo + bar;
                    a[j + k] = foo - bar;
                }
            }
        }
    }
 
    vector<long long> multiply(vector<long long> &a, vector<long long> &b) {
        ll sz = a.size() + b.size() - 1;
        ll logN = 0;
        while ((1 << logN) < sz) logN++;

        vector<cd> aa(1 << logN, 0), bb(1 << logN, 0);

        for (ll i = 0; i < a.size(); i++) aa[i] = a[i];
        for (ll i = 0; i < b.size(); i++) bb[i] = b[i];

        fft(aa, logN, 1);
        fft(bb, logN, 1);

        for (ll i = 0; i < aa.size(); i++) {
            aa[i] *= bb[i];
        }

        fft(aa, logN, -1);
        vector<long long> res(sz);
        for (ll i = 0; i < sz; i++) {
            res[i] = (long long)(aa[i].real() / (1 << logN) + 0.5);
        }
        return res;
    }
};

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	vector<ll> a, b;
	for(auto x: s){
		if(x == 'A'){
			a.pb(0);
			b.pb(1);
		}
		else{
			a.pb(1);
			b.pb(0);
		}
	}

	reverse(a.begin(), a.end());
/*
	fr(i, a.size()) cout << a[i] << ' ';
	cout << endl;

	fr(i, b.size()) cout << b[i] << ' ';
	cout << endl;
*/
	vector<ll> ret = FFT::multiply(a, b);
/*
	fr(i, ret.size()) cout << ret[i] << ' ';
	cout << endl;
*/
	for(ll i = s.size(); i < ret.size(); i++){
		cout << ret[i] << endl;
	}
	cout << endl;
}
