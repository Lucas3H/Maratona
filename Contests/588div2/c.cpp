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

#define MAXN 100010
#define MOD 1000000007

vector<int> adj[8];

int m[7][7];

int main(){
	ios::sync_with_stdio(false);
	int n, M;
	cin >> n >> M;

	int a, b;
	fr(i, M){
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	if(n < 7){
		cout << M << endl;
	}
	else{
		int maximo = 0;

		frr(i, 7){

			mem(m, 0);

			int ans = 0;

			frr(j, 7){
				if(j != i){
					fr(k, adj[j].size()){
						if(adj[j][k] == i) continue;

						ans++;

						m[j][adj[j][k]] = 1;
						m[adj[j][k]][j] = 1;
					}
				}
			}

			ans/=2;

			int melhor = 0;

			frr(j, 7){
				if(i == j) continue;

				int caso = 0;
				fr(k, adj[i].size()){
					if(m[j][adj[i][k]] == 0){
						caso++;
					}
				}

				melhor = max(melhor, caso);
			}

			ans+=melhor;

			maximo = max(maximo, ans);
		}

		cout << maximo << endl;
	}
}
