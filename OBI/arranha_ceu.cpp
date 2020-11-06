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

int nd[4*MAXN];
int a[MAXN];

void build(int i, int l, int r){
    if(l == r) nd[i] = a[l];
    else{
        int m = (l+r)/2;

        build(2*i, l, m);
        build(2*i+1, m+1, r);

        nd[i] = nd[2*i] + nd[2*i+1];
    }
}

void update(int i, int l, int r, int andar, int value){
    if(l == r){
        nd[i] = value;
    }
    else{
        int m = (l+r)/2;

        if(andar <= m) update(2*i, l, m, andar, value);
        else update(2*i + 1, m+1, r, andar, value);

        nd[i] = nd[2*i] + nd[2*i+1];
    }
}

int query(int i, int l, int r, int ql, int qr){
    if(qr < l || r < ql) return 0;
    else if(ql <= l && r <= qr) return nd[i];
    else{
        int m = (l+r)/2;
        return query(2*i, l, m, ql, qr) + query(2*i+1, m + 1, r, ql, qr);
    }
}

int main(){
	ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    frr(i, n) cin >> a[i];
    build(1, 1, n);

    //frr(i, n) cout << query(1, 1, n, 1 , i) << endl;

    fr(i, q){
        int c;
        cin >> c;

        if(c == 1){
            int andar;
            cin >> andar;
            cout << query(1, 1, n, 1, andar) << endl;
        }
        else{
            int andar, pes;
            cin >> andar >> pes;
            update(1, 1, n, andar, pes);
        }
    }
}
