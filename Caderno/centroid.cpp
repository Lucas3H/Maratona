#include<bits/stdc++.h>

using namespace std;

#define MAXN 100010

class Graph{
	public:
    int n;
    set<int> adj[MAXN];
};

/*Vertices são 1, 2, ..., n*/
class Centroid{
	public:
    Graph G, CT; /*Centroid tree*/
	int pai[MAXN], size[MAXN];

	void dfs(int u,int p){
		size[u]=1;
		for(auto x: G.adj[u]){
			if(x != p){
				dfs(x,u);
				size[u]+=size[x];
			}
		}
	}
	
	int find_centroid(int u, int p, int sz){
		for(auto x: G.adj[u]){
			if(x!=p && size[x] > sz/2)
				return find_centroid(x, u, sz);
		}
		return u;
	}

	void decompose(int root, int p){
		dfs(root,root);
		int c = find_centroid(root,root, size[root]);
		
		pai[c] = p;

		for(auto x: G.adj[c]){
			G.adj[x].erase(c);
			decompose(x, c);
		}
	}
};

int main(){
    C.decompose(1, 0);
}