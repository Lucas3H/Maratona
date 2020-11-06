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
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 450
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

int n, r, q;

vector<pii> planet;
vector<pair<pii, pii>> query[2];
int dist[MAXN][MAXN][2];
int ans[100010];
set<int> auxT;
vector<int> T;

void read(){
	cin >> n >> r;

	frr(i, n){
		frr(j, n){
			dist[i][j][0] = MOD;
			dist[i][j][1] = MOD;
		}
	}

	frr(i, n){
		int t;
		cin >> t;
		planet.pb({t, i});
		auxT.insert(t);
	}

	for(auto x: auxT){
		T.pb(x);
	}

	fr(i, r){
		int a, b, wgt;
		cin >> a >> b >> wgt;
		
		dist[a][b][0] = wgt;
		dist[b][a][0] = wgt;

		dist[a][b][1] = wgt;
		dist[b][a][1] = wgt;
	}

	cin >> q;
	frr(i, q){
		int a, b, k, t;
		cin >> a >> b >> k >> t;
		query[t].pb({{k, i}, {a, b}});
	}

	sort(planet.begin(), planet.end());
	sort(query[0].begin(), query[0].end());
	sort(query[1].begin(), query[1].end());
}

int update(int ini, int k, int tp){
	if(tp == 0){
		while(ini < planet.size() && planet[ini].first <= T[k-1]){
			int davez = planet[ini].second;
			frr(i, n){
				frr(j, n){
					dist[i][j][tp] = min(dist[i][j][tp], dist[i][davez][tp] + dist[j][davez][tp]);
				}
			}

			ini++;
		}
	}
	else{
		while(ini >= 0 && planet[ini].first >= T[T.size() - k]){
			int davez = planet[ini].second;
			frr(i, n){
				frr(j, n){
					dist[i][j][tp] = min(dist[i][j][tp], dist[i][davez][tp] + dist[j][davez][tp]);
				}
			}

			ini--;
		}
	}


	return ini;
} 

int main(){
	ios::sync_with_stdio(false);

	read();

	fr(tp, 2){
		int ini = 0, l = 0;
		
		if(tp == 1)
			ini = planet.size() - 1;
		
		fr(i, query[tp].size()){
			ini = update(ini, query[tp][i].f.f, tp);


			//cout << "Passou " << ini << endl;
			pii e = query[tp][i].second;
			int id = query[tp][i].first.second;
			//cout << id << endl;
			ans[id] = dist[e.f][e.s][tp];
		}
	}

	frr(i, q){
		if(ans[i] == MOD){
			cout << -1 << endl;
		}
		else{
			cout << ans[i] << endl;
		}
	}

}
