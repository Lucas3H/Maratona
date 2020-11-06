// 
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

#define MAXN 510
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n, m, q;
vector<int> adj[MAXN], in[MAXN];
int pr[MAXN], pos[MAXN], idade[MAXN], ocup[MAXN];

void read(){
	cin >> n >> m >> q;
	frr(i, n){
		cin >> idade[i];
		pos[i] = i;
		ocup[i] = i;
	}

	fr(i, m){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].pb(v2);
		in[v2].pb(v1);
	}
}

int dfs(int v){
	//cout << v << endl;
	pr[v] = 1;
	int ans = idade[ocup[v]];

	for(auto x: in[v]){
		if(!pr[x]){
			ans = min(ans, dfs(x));
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	read();

	while(q--){
		int v1, v2;
		char op;
		cin >> op;

		if(op == 'T'){
			cin >> v1 >> v2;
			ocup[pos[v1]] = v2;
			ocup[pos[v2]] = v1;
			swap(pos[v1], pos[v2]);
		}
		else{
			cin >> v1;

			frr(i, n) pr[i] = 0;

			int ans = 110;

			//cout << "Visitados\n";

			for(int x: in[pos[v1]]){
				if(!pr[x]) ans = min(ans, dfs(x));
			}

			if(ans == 110){
				cout << "*\n";
			}
			else{
				cout << ans << "\n";
			}
		}
		/*
		cout << "POS\n";
		frr(i, n) cout << pos[i] << ' ';
		cout << endl;
		*/

	}
}
