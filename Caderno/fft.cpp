#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
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

struct FFT{
	using cd = complex<double>;
	const double PI = acos(-1);

	void fft(vector<cd> & a, bool invert) {
	    int n = a.size();
	    if (n == 1)
	        return;

	    vector<cd> a0(n / 2), a1(n / 2);
	    for (int i = 0; 2 * i < n; i++) {
	        a0[i] = a[2*i];
	        a1[i] = a[2*i+1];
	    }
	    fft(a0, invert);
	    fft(a1, invert);

	    double ang = 2 * PI / n * (invert ? -1 : 1);
	    cd w(1), wn(cos(ang), sin(ang));
	    for (int i = 0; 2 * i < n; i++) {
	        a[i] = a0[i] + w * a1[i];
	        a[i + n/2] = a0[i] - w * a1[i];
	        if (invert) {
	            a[i] /= 2;
	            a[i + n/2] /= 2;
	        }
	        w *= wn;
	    }
	}

	vector<int> multiply(vector<int> const& a, vector<int> const& b) {
	    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	    int n = 1;
	    while (n < a.size() + b.size()) 
	        n <<= 1;
	    fa.resize(n);
	    fb.resize(n);

	    fft(fa, false);
	    fft(fb, false);
	    for (int i = 0; i < n; i++)
	        fa[i] *= fb[i];
	    fft(fa, true);

	    vector<int> result(n);
	    for (int i = 0; i < n; i++)
	        result[i] = round(fa[i].real());
	    return result;
	}
};
