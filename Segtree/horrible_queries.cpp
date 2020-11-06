// https://www.spoj.com/problems/HORRIBLE/

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

ll nd[4*MAXN], v[MAXN], lz[4*MAXN];

void build(int i, int l, int r){
    if(l == r) {
        nd[i] = v[l];
        lz[i] = 0;
    }
    else{
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);

        lz[i] = 0;
        nd[i] = nd[2*i] + nd[2*i+1];
    }
}

void push(int i, int l, int r){
    nd[i] += lz[i]*(r - l +1);

    if(l < r){
        lz[2*i]+=lz[i];
        lz[2*i+1]+=lz[i];
    }

    lz[i] = 0;
}

void update(int i, int l, int r, int ql, int qr, ll val){
    push(i, l, r);

    if(ql > r || qr < l) return;
    else if(ql <= l && r <= qr) {
        lz[i]+=val;
        push(i, l, r);
    }
    else{
        int mid = (l + r)/2;

        update(2*i, l, mid, ql, qr, val);
        update(2*i + 1, mid + 1, r, ql, qr, val);

        nd[i] = nd[2*i] + nd[2*i+1];
    }
}

ll query(int i, int l, int r, int ql, int qr){
    push(i, l, r);
    if(ql > r || l > qr) return 0;
    else if(ql <= l && r <= qr) return nd[i];

    else{
        int mid = (l+r)/2;
        return query(2*i, l, mid, ql, qr) + query(2*i+1, mid+1, r, ql, qr);
    }
}

int main(){
	ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;

        frr(i, n) v[i] = 0;

        build(1, 1, n);

        ll op, a, b, d;
        while(c--){
            cin >> op >> a >> b;

            if(op == 0){
                cin >> d;

                update(1, 1, n, a, b, d);
            }
            else{
                cout << query(1, 1, n, a, b) << endl;
            }
        }
    }

}
