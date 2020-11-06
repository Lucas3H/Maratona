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

set<int> adj[50];
int pr[50];
vector<int> ans;

int dfs(int v, int pai){
	ans.pb(v);
	pr[v] = 1;

	int ret = 1;

	for(auto x: adj[v]){
		if(!pr[x]){
			ret *= dfs(x, v);
		}
		else{
			if(x != pai) return 0;
		}
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		fr(i, 26) {
			adj[i].clear();
			pr[i] = 0;
		}

		ans.clear();

		string s;
		cin >> s;

		fr(i, s.size() - 1){
			adj[s[i] - 'a'].insert(s[i+1] - 'a');
			adj[s[i+1] - 'a'].insert(s[i] - 'a');
		}

		int deu = 1;
		fr(i, 26){
			if(adj[i].size() > 2) deu = 0;
		}

		fr(i, 26){
			if(!pr[i] && adj[i].size() <= 1) deu*=dfs(i, i);
		}

		fr(i, 26){
			if(!pr[i]) deu = 0;
		}

		if(!deu) cout << "NO" << endl;
		else{
			cout << "YES\n";
			fr(i, 26){
				cout << (char)('a' + ans[i]);
			}

			cout << endl;
		}
	}
}
