#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

int n;
int nivel[MAXN], pai[MAXN], maior_filho[MAXN];
vector<int> aresta[MAXN];
vector<pii> population[MAXN];
vector<int, pii> city[MAXN];

void dfs(int v, int niv){
	maior_filho[v] = 0;
	fr(i, aresta[v].size()){
		int e = aresta[v][i];

		if(population[e] > population[maior_filho]) maior_filho = e;

		if(nivel[e] == -1){
			nivel[e] = niv+1;
			pai[e] = v;
			dfs(e, niv+1);
		}
	}
}

int main(){
	int t;
	cin >> t;

	while(t--){
		cin >> n;

		//Dar clear em tudo

		frr(i, n){
			int p;
			cin >> p;
			population.pb(mp(p, i));
		}

		frr(i, n-1){
			int x, y;
			cin >> x >> y;

			aresta[x].pb(y);
			aresta[y].pb(x);
		}

		int Cap = max_element(population.begin(), population.end());
		mem(nivel, -1);
		nivel[C] = 0;
		dfs(C);

		fr(i, n){
			city.pb(nivel[population[i]], population[i]);
		}

		sort(city.begin(), city.end());

		int fim1 = -1, M = 0, fim2 = -1;
		int resp[MAXN];
		frm(i, n){
			if(city[i].first >= 2){
				resp[i] = Cap.second;

				if(city[i].second.first > city[M].second.first) M = i;

		
				if(city[i].first == 2 && fim2 == -1){
					fim2 = i;
				}
			}
			else if(city[i].first == 1 && fim1 == -1) fim1 = i;
		}

		resp[0] = city[M].second.second;


		if(population[maior_filho[0]] > population[M]){
			int maxim = 0;
			frr(i, fim1){
				if(i != maior_filho[0]){
					resp[i] = maior_filho[0];
				} 
			}


		}





















		if(city[M].first > 2){
			frr(i, fim) resp[i] = city[M].second.second;
		}
		else{	
			int dad = pai[city[M].second.second];

			int aux = 0;
			frr(i, fim){
				if(pai[city[i].second.second] != dad) aux = 0;
			}

			if(aux == 0 && )

		}
	}	
}
