#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef pair<int,int> pii;
typedef pair<int, int> pint;
typedef pair<double, double> ponto;
typedef vector<vector<int>> matrix;

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

FFT f;

int main(){
	ios::sync_with_stdio(false);
	string s, t;
	vector<int> a, b, c, d, A, B, C, D;
	cin >> s >> t;

	int n = s.size();

	fr(i, n){
		if(s[i] == 'A'){
			a.pb(1);
			b.pb(0);
			c.pb(0);
			d.pb(0);
		}
		else if(s[i] == 'C'){
			a.pb(0);
			b.pb(1);
			c.pb(0);
			d.pb(0);
		}
		else if(s[i] == 'T'){
			a.pb(0);
			b.pb(0);
			c.pb(1);
			d.pb(0);
		}
		else{
			a.pb(0);
			b.pb(0);
			c.pb(0);
			d.pb(1);
		}
	}

	fr(i, t.size()){
		if(t[i] == 'A'){
			A.pb(1);
			B.pb(0);
			C.pb(0);
			D.pb(0);
		}
		else if(t[i] == 'C'){
			A.pb(0);
			B.pb(1);
			C.pb(0);
			D.pb(0);
		}
		else if(t[i] == 'T'){
			A.pb(0);
			B.pb(0);
			C.pb(1);
			D.pb(0);
		}
		else{
			A.pb(0);
			B.pb(0);
			C.pb(0);
			D.pb(1);
		}
	}

	A.resize(n);
	B.resize(n);
	C.resize(n);
	D.resize(n);

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	reverse(C.begin(), C.end());
	reverse(D.begin(), D.end());

	vector<int> ans1, ans2, ans3, ans4;

	ans1 = f.multiply(a, A);
	ans2 = f.multiply(b, B);
	ans3 = f.multiply(c, C);
	ans4 = f.multiply(d, D);

/*	
	for(int i = 0; i < ans3.size(); i++) cout << ans3[i] <<" ";
	cout << endl;
		

	fr(i, n) cout << c[i] << " ";
	cout << endl;

	fr(i, n) cout << C[i] << " ";
	cout << endl;
*/
	int ans = 0;

	for(int i = n - 1; i < n + s.size() - t.size(); i++){
		ans = max(ans1[i] + ans2[i] + ans3[i] + ans4[i], ans);
		//cout << ans1[i] + ans2[i] + ans3[i] + ans4[i] << endl;
	}

	cout << t.size() - ans << endl;
}
