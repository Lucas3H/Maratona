#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

#define fr(i, n) for(int i = 0; i < n; i++)
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
#define mp make_pair
#define pq priority_queue

#define MAXN 110

int m[MAXN][MAXN], pedras[MAXN*MAXN + 1000], processado[MAXN*MAXN + 1000];
int n;

vector<pii> v[MAXN*MAXN + 1000];

void Djikstra(int S){

	for(int i = 0; i < MAXN*MAXN; i++) pedras[i] = 10010;
	pedras[S] = 0;

	pq<pii, vector<pii>, greater<pii>> fila;

	fila.push(mp(0, S));

	while(true){
		int davez = -1;

		while(!fila.empty()){
			int atual = fila.top().second;
			fila.pop();

			if(!processado[atual]){
				processado[atual] = 1;
				davez = atual;

//				cout << "Atual: " << atual << endl;

				break;
			}
		}

		if(davez == -1) break;

		for(int i = 0; i < v[davez].size(); i++){

			int vizinho = v[davez][i].second;
			int i1 = vizinho/(n+2), j1 = vizinho%(n+2);

			if(vizinho < n+2 || vizinho%(n+2) == 0 || vizinho%(n+2) == n+1 || vizinho > n*(n+2) + n) continue;

			if(pedras[vizinho] > pedras[davez] + m[i1][j1]){
				pedras[vizinho] = pedras[davez] + m[i1][j1];
				fila.push(mp(pedras[vizinho], vizinho));
			}
		}

	}
}

int main(){

	cin >> n;

	frr(i, n){
		for(int j = 1; j <=n ; j++) cin >> m[i][j];
	}
	frr(i, n){
		m[0][i] = 1;
		m[n+1][i] = 1;
		m[i][0] = 1;
		m[i][n+1] = 1;
	}

	for(int i = 0; i < MAXN*MAXN; i++) processado[i] = 0;

	frr(i, n){
		for(int j = 1; j <=n ; j++){
			v[i*(n+2)+j].pb(mp(m[i][j] + m[i-1][j], (i-1)*(n+2) + j));
			v[i*(n+2)+j].pb(mp(m[i][j] + m[i][j-1], i*(n+2) + (j-1)));
			v[i*(n+2)+j].pb(mp(m[i][j] + m[i+1][j], (i+1)*(n+2) + j));
			v[i*(n+2)+j].pb(mp(m[i][j] + m[i][j+1], i*(n+2) + (j+1)));
		}
	}

	Djikstra(n*(n+2)+n);

	cout << pedras[1*(n+2)+1] << endl;
/*
	frr(i, n){
		for(int j = 1; j <=n ; j++) cout << pedras[i*(n+2)+j] << " ";
		cout << endl;
	}*/
}
2
