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

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

pii nd[4*MAXN];
int eh_folha[4*MAXN];
pii bd[MAXN];

void build(int i, int l, int r){
    if(l == r){
        folha[i] = 1;
        nd[i] = bd[i];
    }
    else{
        int m = (l+r)/2;

        build(2*i, l, m);
        build(2*i+1, m+1, r);

        if(nd[2*i].f > nd[2*i+1].f) nd[i].f = nd[2*i+1].f;
        else nd[i].f = nd[2*i].f;

        if(nd[2*i].s > nd[2*i+1].s) nd[i].s = nd[2*i+1].s;
        else nd[i].s = nd[2*i].s;
    }
}

void update(int i, int l, int r, int balde, int valor){
    if(l == r){
        if(nd[i].s < valor) {
            nd[i].s = valor;
            bd[i].s = valor;
        }
        else if(nd[i].f > valor){
            nd[i].f = valor;
            nd[i].s = valor;
        }
    }

    int m = (l+r)/2;

    if(m >= balde) update(2*i, l, m, balde, valor);
    else update(2*i+1, m+1, r, balde, valor);

    if(l == r-1){
        if(nd[2*i].s - nd[2*i+1].f > nd[2*i+1].s - nd[2*i].f){
            nd[i].f = nd[2*i+1].f;
            nd[i].s = nd[2*i].s;
        }
        else{
            nd[i].f = nd[2*i].f;
            nd[i].s = nd[2*i+1].s;
        }
    }
    else if(folha[2*i]){
        if(nd[2*i].s - nd[2*i+1].f > nd[2*i+1].s - nd[2*i].f){
            nd[i].f = nd[2*i+1].f;
            nd[i].s = nd[2*i].s;
        }
        else{
            nd[i].f = nd[2*i].f;
            nd[i].s = nd[2*i+1].s;
        }
    }
    

}

int main(){
	ios::sync_with_stdio(false);
}
