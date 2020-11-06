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

#define MAXN 1000000
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	frr(ts, t){
		int edges[2100], val[2100];
		vector<int> adj[110];
		int c, d, x[110];
		cin >> c >> d;

		vector<int> momento[2000];
		pq<pii, vector<pii>, greater<pii>> fila;

		for(int i = 2; i <= c; i++) {
			cin >> x[i];

			if(x[i] < 0) momento[-x[i]].pb(i);
			else fila.push(mp(x[i], i));
		}

		x[1] = 0;
		momento[0].pb(1);

		frr(i, d){
			int v1, v2;
			cin >> v1 >> v2;
			adj[v1].pb(2*i+1);
			adj[v2].pb(2*i + 2);
			edges[2*i + 1] = v2;
			edges[2*i + 2] = v1;
		}

		set<int> foram;
		int real_time[110];
		fr(tempo, 1000){
			if(momento[tempo].size() == 0) continue;

			if(foram.size() < tempo){
				int tam = foram.size();
				for(int j = 0; j < tempo - tam; j++){
					pii davez = fila.top();
					fila.pop();

					for(auto u: adj[davez.s]){
						if(foram.find(edges[u]) != foram.end() && real_time[edges[u]] < davez.f){
							val[u] = davez.f - real_time[edges[u]];
						}
						else{
							val[u] = MAXN;
						}
					}

					real_time[davez.s] = davez.f;
					foram.insert(davez.s);
				}
			}

			int tempo_atual = -1;


			for(auto x: foram){
				tempo_atual = max(real_time[x], tempo_atual);
				//cout << real_time[x] << " ";
			}

			tempo_atual++;

			//cout << " maximo " << tempo_atual << endl;

			for(int y: momento[tempo]){
				for(auto u: adj[y]){
					//cout << u << endl;
					if(foram.find(edges[u]) != foram.end() && real_time[edges[u]] < tempo_atual){
						val[u] = tempo_atual - real_time[edges[u]];
						//cout << "fuck " << real_time[edges[u]] << endl;
					}
					else{
						val[u] = MAXN;	
					}
				}
			}

			for(int y: momento[tempo]){
				real_time[y] = tempo_atual;
				foram.insert(y);
			}
		}

		
		int tam = fila.size();
		for(int j = 0; j < tam; j++){
			pii davez = fila.top();
			fila.pop();

			for(auto u: adj[davez.s]){
				if(foram.find(edges[u]) != foram.end() && real_time[edges[u]] < davez.f){
					val[u] = davez.f - real_time[edges[u]];
				}
				else{
					val[u] = MAXN;
				}
			}

			real_time[davez.s] = davez.f;
			foram.insert(davez.s);
		}

		/*
			x[i], x[edges[edge]], i_edge, ind
		*/



		cout << "Case #" << ts << ": ";

		for(int i = 1; i <= d; i++){
			cout << min(val[2*i+1], val[2*i+2]) << " ";
		}

		cout << endl;
	}
}
