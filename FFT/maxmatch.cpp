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

	void fft(vector<cd>& a, bool invert){ 
		vector<cd> aux = a;
		int log2n = (int)(log2(a.size()) + 0.000001);

	    for(int i = log2n - 1; i >= 0; i--){
	    	double ang = 2 * PI / (1 << (log2n - i)) * (invert ? -1 : 1);
	    	cd w(1), wn(cos(ang), sin(ang));
	    	int pot2 = (1 << i);

	    	for(int j = 0; j < (1 << i); j++){

	    		for(int k = 0; k < (1 << (log2n - i - 1)); k++){
	    			cd t = w * aux[j + k*2*pot2 + pot2];
	    			a[j + k*pot2] = aux[j + k*2*pot2] + t;
			        a[j + k*pot2 + (1 << (log2n - 1))] = aux[j + k*2*pot2] - t;
			        if (invert) {
			            a[j + k*pot2] /= 2;
			            a[j + k*pot2 + (1 << (log2n - 1))] /= 2;
			        }
			        w *= wn;
			    }
	    	}
	    	aux = a;
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
	string s;
	vector<int> a, b, c, A, B, C;
	cin >> s;

	int n = s.size();

	fr(i, s.size()){
		if(s[i] == 'a'){
			a.pb(1);
			b.pb(0);
			c.pb(0);
			A.pb(1);
			B.pb(0);
			C.pb(0);
		}
		else if(s[i] == 'b'){
			a.pb(0);
			b.pb(1);
			c.pb(0);
			A.pb(0);
			B.pb(1);
			C.pb(0);
		}
		else{
			a.pb(0);
			b.pb(0);
			c.pb(1);
			A.pb(0);
			B.pb(0);
			C.pb(1);
		}
	}

	reverse(A.begin(), A.end());
	/*	
		for(auto x: a){
		cout << x << " ";
	}
	cout << endl;

	for(auto x: A){
		cout << x << " ";
	}
	cout << endl;
	*/

	reverse(B.begin(), B.end());
	reverse(C.begin(), C.end());

	vector<int> ans1, ans2, ans3;

	ans1 = f.multiply(a, A);
	ans2 = f.multiply(b, B);
	ans3 = f.multiply(c, C);



	int val = 0;
	set<int> ans;

	for(int i = n; i < ans1.size(); i++){
		if(val < ans1[i] + ans2[i] + ans3[i]){
			val = ans1[i] + ans2[i] + ans3[i];
			ans.clear();
			ans.insert(i);
		}
		else if(val == ans1[i] + ans2[i] + ans3[i]){
			ans.insert(i);
		}
	}

	cout << val << endl;
	for(auto x: ans){
		cout << x - n + 1 << " ";
	}
	cout << endl;
}
