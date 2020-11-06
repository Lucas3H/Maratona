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

#define MAXN 10010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

vector<pii> adj[MAXN];
int n, m;
int prof[MAXN], pr[MAXN];
int cicAreTot[MAXN], cicVerTot[MAXN];
int cicAreI[MAXN], cicVerI[MAXN];
int totI;

int v, u;

void dfs(int s, int ind, int pai){
	pr[s] = 1;

	for(pii p: adj[s]){
		int u = p.f, i = p.s;

		if(!pr[u]){
			prof[u] = prof[s] + 1;
			dfs(u, i, s);

			cicAreTot[ind] += cicAreTot[i];
			cicAreI[ind] += cicAreI[i];
		}
		else{
			/*cout << u << " | " << s << endl;
			cout << prof[u] << " / " << prof[s] << endl;
			*/
			if(prof[u] < prof[s] && u != pai){
				cicVerTot[u]++;
				cicAreTot[i]++;
				cicAreTot[ind]++;
			
				if((prof[u] - prof[s])%2 == 0){
					totI++;
					cicVerI[u]++;
					cicAreI[i]++;
					cicAreI[ind]++;
				}
			}
		}
	}

	cicAreTot[ind]-=cicVerTot[s];
	cicAreI[ind]-=cicVerI[s];
}

vector<int> ans;

void read(){
	cin >> n >> m;

	frr(i, m){
		int u, v;
		cin >> u >> v;

		adj[u].pb(mp(v, i));
		adj[v].pb(mp(u, i));
	}
	frr(i, n) prof[i] = -1;

	frr(i, n){
		if(prof[i] == -1){
			prof[i] = 0;
			dfs(i, 0, 0);
		}
	}
/*
	frr(i, n){
		cout << cicVerI[i] << " ";
	}

	cout << endl;
*/
	frr(i, m){
		//cout << cicAreI[i] << " ";
		if(totI > 0){
			if(cicAreTot[i] == totI && cicAreI[i] == totI){
				ans.pb(i);
			}
		}
		else{
			ans.pb(i);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);

	read();
	int t = ans.size();
	cout << t << endl;
	for(int i = 0; i < t; i++) cout << ans[i] <<" ";
	cout << endl;
}
