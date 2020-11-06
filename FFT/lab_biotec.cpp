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

#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

#define MAXN 2600010

struct complex_t {
  double a {0.0}, b {0.0};
  complex_t() {}
  complex_t(double na, double nb) : a{na}, b{nb} {}
  const complex_t operator+(const complex_t &c) const {
    return complex_t(a + c.a, b + c.b);
  }
  const complex_t operator-(const complex_t &c) const {
    return complex_t(a - c.a, b - c.b);
  }
  const complex_t operator*(const complex_t &c) const {
    return complex_t(a*c.a - b*c.b, a*c.b + b*c.a);
  }
};

const int MAX_SUM = 1 << 22;

struct FFT{
	using cd = complex_t;
	const double PI = acos(-1);

	int rev[MAX_SUM << 1];
	cd wi[MAX_SUM << 1];
	cd fa[MAX_SUM << 1], fb[MAX_SUM << 1];

	void fft(cd a[], int n, bool invert){ 
		for (int i = 0; i < n; ++i)
	    	if (i < rev[i])
	      		swap(a[i], a[rev[i]]);
			
	  	for (int len = 2; len <= n; len <<= 1) {
	      	double ang = 2 * PI / len * (invert ? -1 : +1);
	    	int len2 = len>>1;

	    	cd wlen(cos(ang), sin(ang));
	    	wi[0] = cd(1, 0);
	    	for (int i = 1; i < len2; ++i)
	      		wi[i] = wi[i-1] * wlen;

	    	for (int i = 0; i < n; i += len) {
	      		cd t;

	      		for(int j = 0; j < len2; j++){
	        		t = a[i + len2 + j] * wi[j];
	        		a[i + len2 + j] = a[i + j] - t;
	        		a[i + j] = a[i + j] + t;
	        	}
	    	}
    	}	

	  	if (invert)
	    	for (int i = 0; i < n; ++i) {
	      		a[i].a /= n;
	      		a[i].b /= n;
	    	}
	} 

	void calc_rev(int n, int log_n) {
	  	for (int i = 0; i < n; ++i) {
			rev[i] = 0;
			
			for (int j = 0; j < log_n; ++j)
			    if (i & (1<<j))
			 		rev[i] |= 1 << (log_n-1-j);
		}
	}

	vector<int> multiply(vector<int> const& a, vector<int> const& b) {
		int n = 1, log2n = 0;
	    while (n < a.size() + b.size()){
	    	n <<= 1;
	    	log2n++;
	    } 

	    fr(i, a.size()) fa[i] = cd((double)a[i], 0.0);
	    fr(i, b.size()) fb[i] = cd((double)b[i], 0.0);

	    calc_rev(n, log2n);

	    fft(fa, n, false);

	    fft(fb, n, false);
	    for (int i = 0; i < n; i++)
	        fa[i] = fa[i]*fb[i];
	    fft(fa, n, true);

	    vector<int> result(n);
	    for (int i = 0; i < n; i++)
	        result[i] = round(fa[i].a);
	    return result;
	}
};


FFT f;

int main(){
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int tot = 0;
	fr(i, s.size()){
		tot += s[i] - 'a' + 1;
	}

	vector<int> a(tot + 1), A(tot + 1);

	int n = s.size();
	int sum = 0;
	a[0] = 1;
	A[tot] = 1;
	fr(i, s.size()){
		sum += s[i] - 'a' + 1;
		a[sum] = 1;
		A[tot - sum] = 1;
	}
	/*
	fr(i, a.size()) cout << a[i] << " ";
	cout << endl;
	fr(i, A.size()) cout << A[i] << " ";
	cout << endl;
	*/
	vector<int> ans = f.multiply(A, a);

	int resp = 0;
	for(int i = tot + 1; i < ans.size();i++){
		if(ans[i] > 0){
			resp++;
		}
	}

	/*
	cout << ans.size() << endl;

	fr(i, ans.size()) cout << ans[i] << " ";
	cout << endl;
	*/
	cout << resp << endl;
}
