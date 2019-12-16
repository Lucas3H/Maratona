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

vector<int> aresta[105];
int dist[105], MD = 0;

void dfs(int v, int d){
	dist[v] = d;
	if(MD < d) MD = d;

	fr(i, aresta[v].size()){
		int e = aresta[v][i];
		if(dist[e] == -1) dfs(e, d+1);
	}
}
int testes = 0;
int main(){
	int n;
	cin >> n;

	while(n != 0){
		testes++;

		frr(i, n){
			aresta[i].clear();
		}

		frr(i, n-1){
			int v1, v2;
			cin >> v1 >> v2;

			aresta[v1].pb(v2);
			aresta[v2].pb(v1);
		}

		int minimo = 110, ind = -1;
		frr(i, n){
			frr(j, n) dist[j] = -1;
			MD = -1;

			dfs(i, 0);

			if(minimo > MD){
				minimo = MD;
				ind = i;
			}

		}

		cout << "Teste "<< testes << endl << ind << endl<< endl;

		cin >> n;
	}

	return 0;	
}
