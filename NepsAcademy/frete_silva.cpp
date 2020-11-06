#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
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

int n, m;
int processado[1010], aresta[1010];
vector<pii> v[1010];

int Prim(int S){
	pq<pii, vector<pii>, greater<pii>> fila;
	fila.push(mp(0, S));
	aresta[S] = 0;

	while(true){
		int davez = -1;

		while(!fila.empty()){
			if(!processado[fila.top().second]){
				davez = fila.top().second;
				fila.pop();
				processado[davez] = 1;
				break;
			}
			else fila.pop();
		}

		if(davez == -1) break;

		for(int i = 0; i < v[davez].size(); i++){
			int e = v[davez][i].first, vt = v[davez][i].second;	

			if(!processado[vt] && aresta[vt] > e){
				aresta[vt] = e;
				fila.push(mp(aresta[vt], vt));
			}
		}
	}

	int sum = 0;
	fr(i, n) sum += aresta[i];
	return sum;

}

int main(){
	cin >> n >> m;

	mem(processado, 0);
	fr(i, n) aresta[i] = 1010;

	int v1, v2, c;
	fr(i, m){
		cin >> v1 >> v2 >> c;

		v[v1].pb(mp(c, v2));
		v[v2].pb(mp(c, v1));
	}

	cout << Prim(0) << endl;;

}
