#include<bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define ROOT 1

/*Variaveis RMQ*/
int cont = 1;

int height[2*MAXN];
int name[2*MAXN];    
int rmq[8*MAXN];

int pre_ord[MAXN];

/*Variaveis Grafo*/
int n;
vector<int> adj[MAXN];
int pr[MAXN];

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

int main(){
    int t;
    cin >> t;

    for(int ct = 1; ct <= t; ct++){
            
        cin >> n;

        for(int i = 1; i <= n; i++) {
            pr[i] = 0;
            adj[i].clear();
        }
        for(int i = 1; i <= n; i++){
            int m, v;
            cin >> m;

            for(int j = 1; j <= m; j++){
                cin >> v;
                adj[v].push_back(i);
                adj[i].push_back(v);
            }
        }

        cont = 1;
        dfs(ROOT, 1);

        height[0] = 100000000;
        build(1, 1, cont-1);
    /*
        for(int i = 1; i < cont; i++) cout << height[i] << " ";
        cout << endl;
    
        for(int i = 1; i < cont; i++) cout << name[i] << " ";
        cout << endl;
    */    
        int q;
        cin >> q;

        cout << "Case " << ct << ":" << endl;
        while(q--){
            int v1, v2;
            cin >> v1 >> v2;

            if(pre_ord[v1] > pre_ord[v2]) swap(v1, v2);

            cout << name[query(1, 1, cont - 1, pre_ord[v1], pre_ord[v2])] << endl;
        }
    }
}