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

vector<int> adj[MAXN];
queue<int> caminho;
map<pii, bool> deletada;

void achar_caminho(int v){
	cout << v << endl;

	fr(i, adj[v].size()){
		int e = adj[v][i];

		if(deletada[mp(e, v)] == 1) continue;

		deletada[mp(e, v)] = 1;
		deletada[mp(v, e)] = 1;

		achar_caminho(e);
	}

	caminho.push(v);
}

int main(){
	int n, m;
	cin >> n >> m;

	fr(i, m){
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	stack<int> grau_impar;
	frr(i, n){
		if(adj[i].size()%2 == 1) grau_impar.push(i);
	}

	if(grau_impar.size() > 2 || grau_impar.size() == 1) cout << "Nao tem caminho euleriano.\n";
	else{
		int inicio;
		if(grau_impar.size() == 2) inicio = grau_impar.top();
		else inicio = 1;

		achar_caminho(inicio);

		while(caminho.size()>0){
			cout << caminho.front() << " ";
			caminho.pop();
		}
		cout << endl; 
	}	

	return 0;
}
