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
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 50010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n, nv;
string v[102];
map<vector<char>, int> m;
vector<pii> adj[MAXN];
vector<int> ind[MAXN];

vector<char> wt;
int is_inside(int ind){
	int i = 0;

	int t1 = wt.size(), t2 = v[ind].size();

	while(i < t1 && i < t2 && wt[i] == v[ind][i]) i++;

	if(i < t1 && i < t2) return -1;

	return abs(t1 - t2);
/*
	vector<char> ret;

	if(i == wt.size() && i == v[ind].size()) return ret;
	else if(i == wt.size()) {
		for(int j = wt.size(); j < v[ind].size(); j++){
			ret.pb(v[ind][j]);
		}
		return ret;
	}
	else if(i == v[ind].size()){
		for(int j = v[ind].size(); j < wt.size(); j++){
			ret.pb(wt[j]);
		}

		return ret;
	}
	else{
		ret.pb('-');
		return ret;
	}*/
}

vector<char> w;

void buildVertex(int col, int linha){
	reverse(w.begin(), w.end());

	int pos = ind[linha][col];

	if(col == 0){
		adj[1].pb(mp(-pos, 0));
	}

	fr(i, n){
		wt = w;
		int aux = is_inside(i);
		
		if(aux == -1) continue;
		else if(aux == 0){
			adj[pos].pb(mp(0, v[i].size()));
			continue;
		}
		else if(v[i].size() < w.size()){
			adj[pos].pb(mp(ind[linha][v[linha].size() - aux], v[i].size()));	
		}
		else{
			adj[pos].pb(mp(ind[i][v[i].size() - aux], w.size()));
		}
	}
}

int read(){
	cin >> n;

	fr(i, nv) {
		adj[i].clear();
		ind[i].clear();
	}

	nv = 2;
	int sum = 2;

	fr(i, n){
		cin >> v[i];
		fr(j, v[i].size()){
			ind[i].pb(sum++);
		}
	}

	nv = sum;

	fr(i, n){
		vector<char> usa;
		frm(j, v[i].size()){
			usa.pb(v[i][j]);

			w = usa;

			buildVertex(j, i);
			sum++;
		}
	}

	return n;
}

int bfs(){

	pq<pii, vector<pii>, greater<pii>> fila;
	fila.push(mp(0, 1));
	int dist[MAXN];

	fr(i, nv) dist[i] = MOD;
	int pai[MAXN];

	dist[1] = 0;

	for(pii e: adj[1]){
		fila.push(mp(e.s, e.f));
	}

	while(!fila.empty()){
		pii p = fila.top();
		fila.pop();

		int davez = p.s;

		if(davez < 0){
			davez = -davez;
			for(pii e: adj[davez]){
				if(e.f <= 0) continue;
				if(dist[e.f] > e.s && e.s != 0){
					fila.push(mp(e.s, e.f));
					dist[e.f] = e.s;
					pai[e.f] = davez;
				}	
			}
		}
		else{
			for(pii e: adj[davez]){
				if(e.f < 0) continue;
				if(dist[e.f] > dist[davez] + e.s && dist[davez] + e.s != 0){
					fila.push(mp(dist[davez] + e.s, e.f));
					dist[e.f] = dist[davez] + e.s;
					pai[e.f] = davez;
				}	
			}
		}
	}
	/*
	fr(i, nv) cout << dist[i] << " ";
	cout << endl;
	*/
	/*
	fr(i, nv){
		cout << i << " | pai: " << pai[i] << endl;
	}*/

	if(dist[0] == MOD) return -1;
	else return dist[0];
}

int main(){

	ios::sync_with_stdio(false);

	while(read()){
		
		/*
		fr(i, nv){
			cout << i << endl << "Vertices: ";

			for(auto y: adj[i]){
				cout << y.f << '/' << y.s << " ";
			}
			cout << endl;

		}
		*/
		
		int ans = bfs();
		cout << ans << "\n";
	}
}