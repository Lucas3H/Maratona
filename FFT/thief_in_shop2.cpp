#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(long long i = 0; i < n; i++)
#define frr(i, n) for(long long i = 1; i <= n; i++)
#define frm(i, n) for(long long i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<long long,long long> pii;
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
    
    vector<long long> fastxp(vector<long long> a, long long exp){
    	if(exp == 1) return a;

    	vector<long long> aux = fastxp(a, exp/2);

    	aux = multiply(aux, aux);

    	if(aux.size() > 1000010) 
    		aux.resize(1000010);

    	if(exp%2 == 1)
    		aux = multiply(aux, a);

    	if(aux.size() > 1000010) 
    		aux.resize(1000010);

    	fr(i, aux.size()) if(aux[i]) aux[i] = 1;

    	return aux;
    }
};

long long n, k;
#define MAXS 1000010

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> k;

	long long a[MAXN], maior = 0;
	fr(i, n) cin >> a[i], maior = max(maior, a[i]);

	vector<long long> ans(maior + 1);

	fr(i, n){
		ans[a[i]] = 1;
	}

	ans = FFT::fastxp(ans, k);

	long long resp = 0;
	fr(i, ans.size()) if(ans[i]) cout << i << " ";
	cout << endl;
}
