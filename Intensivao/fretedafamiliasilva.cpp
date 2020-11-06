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

#define MAXN 1010

int pai[MAXN], peso[MAXN];
int mst;
struct edge{
    int u;
    int v;
    int w;
};

edge e[10*MAXN];

bool ord(edge a, edge b) {
    return a.w < b.w;
}
int find(int x){
    if(pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int a, int b, int w){
    a = find(a);
    b = find(b);

    if(a == b) return;

    mst += w;

    if(peso[a] < peso[b]) swap(a, b);

    pai[b] = a;
    peso[a] += peso[b];
}

int main(){
		ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    fr(i, m) cin >> e[i].u >> e[i].v >> e[i].w;

    sort(e, e+m, ord);

    fr(i, n){
        pai[i] = i;
        peso[i] = 1;
    }

    fr(i, m) {
        join(e[i].u, e[i].v, e[i].w);
    }
    cout << mst << endl;
}
