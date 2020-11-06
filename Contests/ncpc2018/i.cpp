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
#define DIG 1002

int n;
pair<string, string> p[1010];
string s;

bool comp(pair<string, string> a, pair<string, string> b){
	int i = 0;
	while((a.s)[i] == (b.s)[i] && i < (a.s).size())
		i++;

	return (a.s)[i] > (b.s)[i];
}

bool operator <=(string a, string b){
	int i = 0;
	while((a)[i] == (b)[i] && i < a.size())
		i++;

	if(i == a.size()) return true;
	else return a[i] <= b[i];
}

string operator+(string a, string b){
	string ans;
	int carry = 0;
	frm(i, a.size()){
		int val = (a[i] - '0') + (b[i] - '0') + carry;

		if(val >= 10){
			val%=10;
			carry = 1;
		}
		else carry = 0;

		ans = (char)(val + '0') + ans;
	}

	return ans;
}

void read(){
	cin >> n >> s;

	int t = DIG - s.size();
	fr(j, t) s = '0' + s;

	frr(i, n){
		string a, b;
		cin >> a >> b;

		t = DIG - b.size();
		fr(j, t) b = '0' + b;

		p[i] = {a, b};
	}

	sort(p + 1, p + n + 1, comp);
}

int main(){
	ios::sync_with_stdio(false);

	read();

	vector<string> ans;

	string soma;
	fr(i, DIG) soma = '0' + soma;

	frr(i, n){

		if((soma + p[i].s) <= s){
			ans.pb(p[i].f);
			soma = soma + p[i].s;
		}
	}

	if(soma == s){
		cout << ans.size() << endl;
		for(auto x: ans) cout << x << endl;
	}
	else{
		cout << 0 << endl;
	}
}	
