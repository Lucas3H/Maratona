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

#define MAXN 110

struct edge{
    int u;
    int v;
    int w;
};

int pai[MAXN], peso[MAXN];
vector<pii> mst;
int n, m;
vector<edge> e;

bool ord(edge a, edge b){
    return a.w < b.w;
}

int find(int x){
    if(pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int a, int b){
    int A = a, B = b;

    a = find(a);
    b = find(b);

    if(a == b) return;

    if(peso[a] < peso[b]) swap(a, b);

    pai[a] = b;
    peso[b] += peso[a];

    mst.pb(mp(A, B));
}

int main(){
		ios::sync_with_stdio(false);

    int test = 1;
    cin >> n;
    while(n > 0){
        cin >> m;

        e.clear();
        mst.clear();

        frr(i, n){
              pai[i] = i;
              peso[i] = 1;
        }

        fr(i, m){
            edge E;
            cin >> E.v >> E.u >> E.w;
            e.pb(E);
        }

        sort(e.begin(), e.end(), ord);

        fr(i, m){
            join(e[i].u, e[i].v);
        }

        cout << "Teste " << test << endl;
        fr(i, mst.size()) cout << min(mst[i].first, mst[i].second) << " " << max(mst[i].first, mst[i].second) << endl;
        cout << endl;
        cout << endl;
        test++;

        cin >> n;
    }
}
