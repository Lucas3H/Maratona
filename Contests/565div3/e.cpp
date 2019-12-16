#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define ll long long

#define MAXN 200010

vector<int> adj[MAXN], p[2];
int processado[MAXN];

void dfs(int v, int niv){
      processado[v] = 1;
      p[niv].pb(v);

      fr(i, adj[v].size()){
          if(!processado[adj[v][i]]){
              dfs(adj[v][i], 1 - niv);
          }
      }
}

int main(){
	   int quer;
     //cin >> quer;
     scanf("%d", &quer);
     while(quer--){

        int n, m;
        scanf("%d %d", &n, &m);


        frr(i, n) {
          adj[i].clear();
          processado[i] = 0;
        }
        p[0].clear();
        p[1].clear();

        int v1, v2;

        fr(i, m){
            scanf("%d %d", &v1, &v2);
            adj[v1].pb(v2);
            adj[v2].pb(v1);
        }

        dfs(1, 1);

        if(p[0].size() <= n/2){
            printf("%d\n", p[0].size());
            fr(i, p[0].size()) printf("%d ", p[0][i]);
            printf("\n");
        }
        else{
            printf("%d\n", p[1].size());
            fr(i, p[1].size()) printf("%d ", p[1][i]);
            printf("\n");
        }

     }
}
