#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int pai[MAXN], peso[MAXN];

int find(int x){
    if(pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

int join(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    
    if(peso[a] > peso[b]) swap(a, b);

//    cout << "Join " << a << " " << b << endl;

    pai[b] = a;
    peso[a]+=peso[b];

    return a;
}

int main(){
	ios::sync_with_stdio(false);

    int n;
    cin >> n;

    frr(i, n){
        pai[i] = i;
        peso[i] = 1;
    }
    int m;
    cin >> m;

    vector<int> adj[MAXN];

    int a, b;
    fr(i, m){
        cin >> a >> b;
        adj[max(a, b)].pb(min(a, b));
    }

    frr(i, n) sort(adj[i].begin(), adj[i].end());

    set<int> comp;

    frr(i, n){
        map<int, int> lig;
        
    //    cout << "Ligacoes " << i << endl;
        fr(j, adj[i].size()){
            lig[find(adj[i][j])]++;
  //          cout << i <<" " << adj[i][j] << " " << find(adj[i][j]) << " " <<  lig[find(adj[i][j])] << endl;
        }

        int ant = 0, addi = 0;

//        cout << "Vertice "<< i << endl;        
        
        for(auto x:comp){
            x = find(x);
            
    //        cout << x << " " << peso[x] <<" " << lig[x] << endl;
            
            if(peso[x] > lig[x]){
                int newT = join(i, x);

                addi = 1;

                if(ant != 0) newT = join(ant, i);

                ant = x;        
            }
        }

        if(addi == 0) comp.insert(i);
    }

    int ans = 0;
    frr(i, n){
        if(pai[i] == i) ans++;
    }

    cout << ans -1  << endl;
}
