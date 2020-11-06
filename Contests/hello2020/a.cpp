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

int n, m;
vector<string> x, y;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;

	fr(i, n){
		string s;
		cin >> s;
		x.pb(s);
	}
	fr(i, m){
		string s;
		cin >> s;
		y.pb(s);
	}

	int q;
	cin >> q;

	while(q--){
		int t;
		cin >> t;

		t--;

		cout << x[t%n] << y[t%m] << endl;
	}
}
