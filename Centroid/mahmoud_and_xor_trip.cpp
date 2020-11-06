#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll, ll> pll;
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

class Graph{
	public:
    ll n;
    set<ll> adj[MAXN];
};

ll a[MAXN];
ll ans = 0, n;
ll dp[2][20][MAXN];
/*Vertices são 1, 2, ..., n*/
class Centroid{
	public:
    Graph G, CT; /*Centroid tree*/
	ll pai[MAXN], size[MAXN];

	void dfs(ll u,ll p, ll root, ll mask){
		size[u]=1;

		fr(i, 20){
			if(((1 << i)&(a[u]^mask)) == (1 << i))
				dp[1][i][root] ++;
			else
				dp[0][i][root] ++;		
		}
		
		for(auto x: G.adj[u]){
			if(x != p){
				dfs(x,u, root, a[u]^mask);
				size[u]+=size[x];
			}
		}
	}
	
	ll find_centroid(ll u, ll p, ll sz){
		for(auto x: G.adj[u]){
			if(x!=p && size[x] > sz/2)
				return find_centroid(x, u, sz);
		}
		return u;
	}

	void decompose(ll root, ll p){
		dfs(root,root, root, 0);
		ll c = find_centroid(root,root, size[root]);
		
		ll aux[2][20], save[2][20];
		fr(i, 20){
			save[0][i] = dp[0][i][root];
			save[1][i] = dp[1][i][root];
			dp[0][i][root] = 0;
			dp[1][i][root] = 0;
		}
		mem(aux, 0);

		for(auto x: G.adj[c]){
			G.adj[x].erase(c);
			decompose(x, c);

			fr(i, 20){
				aux[0][i] += dp[0][i][x];
				aux[1][i] += dp[1][i][x];
			}
		}

		fr(i, 20){
			//aux[0][i] += (((1 << i)&a[c]) != (1 << i));
			//aux[1][i] += (((1 << i)&a[c]) == (1 << i));
			//cout << c << " " << a[c] << " " << (((1 << i)&a[c]) == (1 << i))*(1 << i) << endl;
			ans += (((1 << i)&a[c]) == (1 << i))*(1 << i);
		}

		for(auto x: G.adj[c]){
			
			/*fr(i, 4){
				cout << c << " " << x << " "<< aux[0][i] << " " << aux[1][i] << endl;
			}
			*/
			fr(i, 20){
				//cout << ans << endl;
				if(((1 << i)&a[c]) == (1 << i)){
					ans += dp[0][i][x]*(aux[0][i] - dp[0][i][x] + 1)*(1 << i);
					ans += (dp[1][i][x])*(aux[1][i] - dp[1][i][x])*(1 << i);
				}
				else{
					ans += (dp[0][i][x])*(aux[1][i] - dp[1][i][x])*(1 << i);
					ans += dp[1][i][x]*(aux[0][i] - dp[0][i][x] + 1)*(1 << i);		
				}

				aux[0][i] -= dp[0][i][x];
				aux[1][i] -= dp[1][i][x];

				//cout << ans << " " << i << " " << aux[0][i] << " " << aux[1][i] << endl;
			}
		}

		//cout << c << " " << ans << endl;

		fr(i, 20){
			dp[0][i][root] = save[0][i];
			dp[1][i][root] = save[1][i];
			//cout << root << ' ' << dp[0][i][root] << endl;
		}
	}
};

Centroid C;

void read(){
	cin >> n;

	frr(i, n) cin >> a[i];

	fr(i, n-1){
		ll x, y;
		cin >> x>> y;
		C.G.adj[x].insert(y);
		C.G.adj[y].insert(x);
	}
}

int main(){
	read();
	C.decompose(1, 0);
	cout << ans << endl;
}