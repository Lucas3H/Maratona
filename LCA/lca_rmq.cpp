#include<bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define ROOT 1

/*Variaveis da Segtree*/
int cont = 1;

int height[2*MAXN];   // Vetor onde é vista a segtree
int name[2*MAXN];     // Nome do vértice que corresponde à i-ésima altura 
int rmq[8*MAXN];      // Nodes da Segtree

int pre_ord[MAXN];           // Pré ordem do vértice i. Usado para ver os ql e qr da segtree

/*Variaveis Grafo*/
int n;
vector<int> adj[MAXN];          
int pr[MAXN];                // Processado


/*Build da Segtree*/

void build(int i, int l, int r){
    if(l == r) rmq[i] = l;    
    else{
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);

        if(height[rmq[2*i]] > height[rmq[2*i+1]]) rmq[i] = rmq[2*i+1];
        else rmq[i] = rmq[2*i];
    }
}

/*Query da Segtree*/
int query(int i, int l, int r, int ql, int qr){
    
    if(l > qr || ql > r) return 0;  
    else if(ql <= l && r <= qr) return rmq[i];
    else{
        int mid = (l+r)/2;

        int lf = query(2*i, l, mid, ql, qr);
        int rg = query(2*i+1, mid+1, r, ql, qr);

        if(height[lf] > height[rg]) return rg;
        else return lf;
    }

}

/*DFS para setar os vetores height, name e pre_order*/
void dfs(int v, int nv){
    pr[v] = 1;

    pre_ord[v] = cont;
    name[cont] = v;
    height[cont++] = nv;
    
    for(int i = 0; i < adj[v].size(); i++){
        int u = adj[v][i];

        if(!pr[u]) {
            dfs(u, nv+1); 

            height[cont] = nv;
            name[cont++] = v;
        }
    }
}

int lca(int a, int b){
    if(pre_ord[a] > pre_ord[b]) swap(a, b);

    return name[query(1, 1, cont - 1, pre_ord[a], pre_ord[b])];
}

int main(){
    cin >> n;

    for(int i = 1; i <= n-1; i++){
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    dfs(ROOT, 1);

    height[0] = 100000000;
    build(1, 1, cont-1);
/*
    for(int i = 1; i < cont; i++) cout << height[i] << " ";
    cout << endl;
    
    for(int i = 1; i < cont; i++) cout << name[i] << " ";
    cout << endl;
*/    
    cout << "Queries: ";
    int q;
    cin >> q;

    while(q--){
        int v1, v2;
        cin >> v1 >> v2;

        cout << lca(a, b) << endl;
    }
}