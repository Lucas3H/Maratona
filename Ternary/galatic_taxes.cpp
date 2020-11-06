// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4898

#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<double,double> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 1010
#define MOD 1000000007

int n, m;

int pr[MAXN];
vector<pair<int, pii>> adj[MAXN];
double dist[MAXN];

double dijk(double t){
    pq<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>> > fila;
    fila.push(mp(0, 1));

    while(true){
        int davez = -1;

        while(!fila.empty()){
            int u = fila.top().s;
            
            if(!pr[u]){
                pr[u] = 1;
                
                dist[u] = fila.top().f;
                //cout << "D " << u << " " << dist[u] << endl;
 
                davez = u;
                break;
             }
            
            fila.pop();
        }

        if(davez == -1) break;

       // cout << "Davez " << davez << endl << endl;

        fr(i, adj[davez].size()){
            int u = adj[davez][i].f;
            double d = dist[davez] + (double)adj[davez][i].s.f*t + (double)adj[davez][i].s.s;

            if(!pr[u]){
              //  cout << d << " || " <<u << endl;

                fila.push(mp(d, u));
            }
        }
    }
    
    double ans = dist[n];

    frr(i, n){
        dist[i] = 0.0;
        pr[i] = 0;
    }
    
    return ans;
}

int main(){

    while(cin >> n >> m){
        frr(i, n){
            pr[i] = 0;
            dist[i] = -1;
            adj[i].clear();
        }

        int v1, v2;
        double a, b;
        fr(i, m){
            cin >> v1 >> v2 >> a >> b;

            adj[v1].pb(mp(v2, mp(a, b)));
            adj[v2].pb(mp(v1, mp(a, b)));
        }

        double l = 0.0, r = 24.0*60.0;
    
        fr(cont, 100){
            double t1 = l + (r - l)/3;
            double t2 = r - (r - l)/3;

           // cout << t1 << " " << dijk(t1) << " | " << t2 << " " << dijk(t2) << endl;

            if(dijk(t1) > dijk(t2)) r = t2;
            else l = t1;            
        
        }

        printf("%.5lf\n", dijk((l+r)/2));
    }
}
