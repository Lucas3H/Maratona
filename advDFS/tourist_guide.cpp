// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1140 
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
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 110
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

int t, n, children;

map<string, int> m;
vector<int> adj[MAXN];
int pr[MAXN], tin[MAXN], low_link[MAXN], is_art[MAXN];
vector<string> v;

void dfs(int v, int pai){
	pr[v] = 1;
	tin[v] = t++;
	low_link[v] = tin[v];

	//cout << v << " " << low_link[v] << endl;

	for(auto x: adj[v]){
		if(x == pai) continue;

		//cout << v << " E " << x<< endl;

		if(!pr[x]){
			dfs(x, v);

			if(v == pai) children++;

			low_link[v] = min(low_link[v], low_link[x]);

			if(low_link[x] >= tin[v]) is_art[v] = 1;
		}
		else{
			low_link[v] = min(low_link[v], tin[x]);
		}
	}

	//cout << v << " " << low_link[v] << endl;
}

int read(){

	if(n == 0) return 0;

	t = 0;
	v.clear();
	m.clear();
	frr(i, n){
		pr[i] = 0;
		is_art[i] = 0;

		adj[i].clear();

		string s;
		cin >> s;
		m[s] = i;
		v.pb(s);
	}

	int r;
	cin >> r;

	frr(i, r){
		string s, T;
		cin >> s >> T;

		int a = m[s], b = m[T];

		adj[a].pb(b);
		adj[b].pb(a);
	}

	frr(i, n){
		if(!pr[i]){
			dfs(i, i);

			if(children <= 1) is_art[i] = 0;
			else is_art[i] = 1;

			children = 0;
		}
	}

	return 1;
}

int main(){
	int test = 1;

	cin >> n;
	while(read()){
		vector<string> ans;
		frr(i, n){
			if(is_art[i]) ans.pb(v[i-1]);
		}
		
		sort(ans.begin(), ans.end());

		cout << "City map #" << test++ << ": " << ans.size() << " camera(s) found\n";
		fr(i, ans.size()){
			cout << ans[i] << endl;
		}

		cin >> n;
		if(n > 0) printf("\n");
	}
}
