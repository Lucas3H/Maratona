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

int n, q;
set<pii> p;

vector<int> adj[2*MAXN];
int baixo[MAXN], cima[MAXN];

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> q;

	while(q--){
		int a, b, deu = 1;
		cin >> a >> b;

		if(a == 1){
			if(cima[b] == 0){
				cima[b] = 1;

				if(baixo[b-1]){
					adj[b].pb(n + b-1);
					adj[n + b - 1].pb(b);
					p.insert(mp(b, b-1));
				}
				if(baixo[b]){
					adj[b].pb(n + b);
					adj[n + b].pb(b);

					p.insert(mp(b, b));
				}
				if(baixo[b+1]){
					adj[b].pb(n + b + 1);
					adj[n + b + 1].pb(b);

					p.insert(mp(b, b+1));
				}
			}
			else{
				cima[b] = 0;

				fr(i, adj[b].size()){
					p.erase(mp(b, adj[b][i] - n));
				}

				adj[b].clear();
 			}
		}
		else{
			if(baixo[b] == 0){

				baixo[b] =1;

				if(cima[b-1]){
					adj[b - 1].pb(n + b);
					adj[n + b].pb(b - 1);
					p.insert(mp(b - 1, b));
				}
				if(cima[b]){
					adj[b].pb(n + b);
					adj[n + b].pb(b);

					p.insert(mp(b, b));
				}
				if(cima[b+1]){
					adj[b + 1].pb(n + b);
					adj[n + b].pb(b + 1);

					p.insert(mp(b + 1, b));
				}
			}
			else{
				baixo[b] = 0;
				//cout << "Sai\n";

				fr(i, adj[n + b].size()){
					p.erase(mp(adj[n + b][i], b));
				}
				
				adj[n + b].clear();
 			}
		}

		if(p.size() > 0) cout << "No\n";
		else cout << "Yes\n";
	}
}
