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

vector<int> aresta[100010];
int pai[100010], peso[100010];
int tot = 1;
int n, m, q;

int find(int x){
	if(pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}

void join(int u, int v){
	int a = find(u), b = find(v);

	if(a == b) return;

	else if(peso[a] > peso[b]) pai[b] = a;
	else if(peso[a] < peso[b]) pai[a] = b;
	else{
		pai[b] = a;
		peso[a]++;
	}
}

void dfs(int v){
	
	fr(j, aresta[v].size()){
		int e = aresta[v][j];

		if(pai[e] == e){
			join(v, e);
			dfs(e);
		}
	}
}

int main(){
	cin >> n >> m;

	pii arestas[100010];

	frr(i, m){
		int v1, v2;
		cin >> v1 >> v2;

		arestas[i] = mp(v1, v2);
	}

	vector<int> nao_cortadas;
	stack<int>cortadas;
	pq<int, vector<int>, greater<int>> aux;

	cin >> q;

	fr(i, q){
		int x;
		cin >> x;
		cortadas.push(x);
		aux.push(x);
	}

	aux.push(MAXN);

	frr(i, m){
		if(aux.top() > i){
			nao_cortadas.pb(i);

		//	cout << "Nao cortada: " << i << endl;
		}
		else aux.pop();
	}

	fr(i, nao_cortadas.size()){
		int x = arestas[nao_cortadas[i]].first, y = arestas[nao_cortadas[i]].second;

		aresta[x].pb(y);
		aresta[y].pb(x);
	}

	frr(i, n){
		pai[i] = i;
		peso[i] = 1;
	}

	int resp = 0;
	frr(i, n){
		if(pai[i] == i){
	//		cout << "OK" << i << endl;
			resp++;
			dfs(i);
		}
	}

	int r[100010];

	fr(i, q){
		//cout << "Cort" << cortadas.top() << endl;
		int v1 = arestas[cortadas.top()].first, v2 = arestas[cortadas.top()].second;

		cortadas.pop();

		//cout<< endl << v1 << " " << v2 << endl;		

		v1 = find(v1);
		v2 = find(v2);

		r[i] = resp;

		if(v1 != v2){
			resp--;
//			aresta[v1].pb(v2);
//			aresta[v2].pb(v1);

			join(v1, v2);
		}

	}

	frm(i, q) cout << r[i] << " ";

	cout << endl;

	return 0;
}
