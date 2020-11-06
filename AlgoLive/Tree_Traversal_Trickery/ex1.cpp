#include<bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define ROOT 1

/*Variaveis das árvores*/
vector<int> adj[MAXN];
int pr[MAXN];
int val[MAXN];
int n;

/*Variaveis do RMQ*/
int pre_ord[MAXN];
int pos_ord[MAXN];
//int lin_tree[2*MAXN];
int ind = 1;

/*BIT*/
int bit[2*MAXN];

void dfs(int v){
    pr[v] = 1;
    pre_ord[v] = ind++;

    for(int i = 0; i < adj[v].size(); i++){
        int u = adj[v][i];

        if(!pr[u]) dfs(u);
    }

    pos_ord[v] = ind++;
}

void update(int i, int val){
    while(i <= ind){
        bit[i] += val;
        i += i & (-i);
    }
}

int query(int i){
    int sum = 0;

    while(i > 0){
        sum += bit[i];
        i -= i & (-i);
    }

    return sum;
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> val[i];

    for(int i = 0; i < n-1; i++){
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    dfs(ROOT);

    /*Setar a BIT*/
    for(int i = 1; i <= n; i++) update(pre_ord[i], val[i]);
        
    int q;
    cin >> q;

    while(q--){
        char op;

        cin >> op;

        if(op == 'u'){
            int v, new_val;
            cin >> v >> new_val;

            update(pre_ord[v], new_val - val[v]);
            val[v] = new_val;
        }
        else{
            int v;
            cin >> v;

            cout << query(pos_ord[v]) - query(pre_ord[v] - 1) << endl;
        }
    }
}