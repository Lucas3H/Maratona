#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int adj[102][102];
int pr[102];
int dist[102][102];

int n, m;

int a[1000010];

void bfs(int v){
		pq<pii, vector<pii>, greater<pii>> fila;
		fila.push(mp(0, v));

		while(true){
				int davez = -1;

				while(!fila.empty()){
						int u = fila.top().second;

						if(!pr[u]){
								davez = u;
								pr[u] = 1;
								dist[v][u] = fila.top().first;
								break;
						}

						fila.pop();
				}

				if(davez == -1) break;

				frr(i, n){
						if(adj[davez][i] == 0) continue;

						if(!pr[i]){
								fila.push( mp( dist[v][davez] + 1, i) );
						}
				}
		}
}

vector<int> ans;

int main(){
		ios::sync_with_stdio(false);
		cin >> n;

		frr(i, n){
				string s;
				cin >> s;

				fr(j, n) {
					adj[i][j+1] = s[j] - '0';
				}
		}

		cin >> m;
		frr(i, m) cin >> a[i];

		frr(i, n){
				mem(pr, 0);
				bfs(i);
		}

		int ant = 1, atu = 2;
		ans.pb(1);
/*
		frr(i, n){
				frr(j, n) cout << dist[i][j] << " ";
				cout << endl;
		}
*/
		while(atu <= m){
				if(dist[a[ant]][a[atu]] < atu - ant){
						//cout << ant << " " <<  atu-1 << endl;
						ans.pb(atu - 1);
						ant = atu - 1;
						atu++;
				}
				else atu++;
		}

		ans.pb(m);
		cout << ans.size() << endl;
		fr(i, ans.size()) cout << a[ans[i]] << " ";
}
