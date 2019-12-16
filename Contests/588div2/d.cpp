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

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 7001
#define MOD 1000000007

ll a[MAXN], b[MAXN];

vector<int> adj[MAXN];
int volta[MAXN];

bool processado[MAXN];

void dfs(int v){
	if(volta[v] != 0) return;
	if(processado[v] == 1) return;
	processado[v] = 1;

//	cout << v << endl;

	fr(i, adj[v].size()){

		if(processado[adj[v][i]] == 1) continue;
		volta[adj[v][i]]--;

		//cout << v << " elimina " << adj[v][i] << endl;

		dfs(adj[v][i]);
	}
}

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	frr(i, n) cin >> a[i];
	frr(i, n) cin >> b[i];

	frr(i, n){
		frr(j, n){
			if(i != j){
				if((a[i] | a[j]) == a[i]){
					adj[i].pb(j);
					volta[j]++;

					//cout << i <<" " << j << endl;
				}
			}
		}
	}

/*	frr(i, n) cout << volta[i].size() <<" ";
	cout << endl;
*/
	frr(i, n) dfs(i);

	ll ans = 0;

	frr(i, n){
		if(!processado[i]) ans+=b[i];
	}

	cout << ans << endl;
}
