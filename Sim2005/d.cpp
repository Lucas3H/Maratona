#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 100010

int n, m, k;
pq< pair<int, pii> > edge;
int pai[20], peso[20], special[20];

vector< pii > adj[16];

ll total = 0;

int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b, int e){
	int x = a, y = b;
	a = find(a);
	b = find(b);

	if(a == b) return;

	if(peso[a] > peso[b]) pai[b] = a;
	else if(peso[a] < peso[b]) pai[a] = b;

	else{
		pai[b] = a;
		peso[a]++;
	}

	adj[x].pb(mp(e, y));
	adj[y].pb(mp(e, x));

	return;
}

void mst(){
	while(!edge.empty()){
		int e = -edge.top().first;
		int a = edge.top().second.first;
		int b = edge.top().second.second;
		
		edge.pop();

		if(find(a) == find(b)) continue;
		else{
			join(a, b, e);
			total += e;
		}
	}
}

void eliminate_leafs(){
	stack<int> non_special_leafs;

	frr(i, n){
		if(adj[i].size() == 1 && !special[i]) non_special_leafs.push(i);
	}

	while(!non_special_leafs.empty()){
		int vl = non_special_leafs.top();
		non_special_leafs.pop();

		int vf = adj[vl][0].second;
		int tam = adj[vl][0].first;

		adj[vl].erase(adj[vl].begin(), adj[vl].begin() + 1);
		
		total -= tam;

		fr(i, adj[vf].size()){
			if(adj[vf][i].second == vl){
				adj[vf].erase(adj[vf].begin() + i, adj[vf].begin() + i + 1);
				break;
			}
		}

		if(adj[vf].size() == 1 && !special[vf]) non_special_leafs.push(vf);
	}
}

int main(){
	int tests;
	cin >> tests;

	while(tests--){
		cin >> n >> m >> k;

		frr(i, n) {
			pai[i] = i;
			peso[i] = 1;
			adj[i].clear();
		}

		fr(i, m){
			int v1, v2, wght;
			cin >> v1 >> v2 >> wght;

			edge.push(mp(-wght, mp(v1, v2)));
		}

		mem(special, 0);
		fr(i, k){
			int sp;
			cin >> sp;
			special[sp] = 1;
		}

		total = 0;

		mst();
		eliminate_leafs();

		cout << total << endl;
	}
}