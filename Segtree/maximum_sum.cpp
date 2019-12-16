// https://www.spoj.com/problems/KGSS/

#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
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

pii nd[4*MAXN];
ll a[MAXN];

void build(int i, int l, int r){
    if(l == r) nd[i] = mp(l, 0);
    else{
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);

        if(a[ nd[2*i].f ] < a[ nd[2*i+1].f ]){
            if(a[ nd[2*i].f ] < a[ nd[2*i+1].s ] ) nd[i] = nd[2*i+1];
            else nd[i] = mp(nd[2*i+1].f, nd[2*i].f);
        }
        else{
            if(a[ nd[2*i+1].f ] < a[ nd[2*i].s ]) nd[i] = nd[2*i];
            else nd[i] = mp( nd[2*i].f, nd[2*i+1].f );
        }
/*
        if(l == mid && mid+1 == r) nd[i] = mp(l, r);
        else if(l == mid){
            pii v[3];
            v[0] = mp(a[l], l);
            v[1] = mp(a[ nd[2*i+1].f ], nd[2*i+1].f);
            v[2] = mp(a[ nd[2*i+1].s ], nd[2*i+1].s);

            sort(v, v+3);

            nd[i] = mp(v[2].s, v[1].s);
        }
        else if( mid+1 == r){
            pii v[3];
            v[0] = mp(a[r], r);
            v[1] = mp(a[ nd[2*i].f ], nd[2*i].f);
            v[2] = mp(a[ nd[2*i].s ], nd[2*i].s);

            sort(v, v+3);

            nd[i] = mp(v[2].s, v[1].s);
        }
        else{
            pii v[3];
            v[0] = mp(a[ nd[2*i+1].f ], nd[2*i+1].f);
            v[1] = mp(a[ nd[2*i+1].s ], nd[2*i+1].s);
            v[2] = mp(a[ nd[2*i].f ], nd[2*i].f);
            v[3] = mp(a[ nd[2*i].s ], nd[2*i].s);

            sort(v, v+4);

            nd[i] = mp(v[3].s, v[2].s);

        }*/
    }

}

void update(int i, int l, int r, int pos, int val){
    if(l == r) a[pos] = val;
    else{
        int mid = (l+r)/2;

        if(pos <= mid) update(2*i, l, mid, pos, val);
        else update(2*i+1, mid+1, r, pos, val);

        if(a[ nd[2*i].f ] < a[ nd[2*i+1].f ]){
            if(a[ nd[2*i].f ] < a[ nd[2*i+1].s ] ) nd[i] = nd[2*i+1];
            else nd[i] = mp(nd[2*i+1].f, nd[2*i].f);
        }
        else{
            if(a[ nd[2*i+1].f ] < a[ nd[2*i].s ]) nd[i] = nd[2*i];
            else nd[i] = mp( nd[2*i].f, nd[2*i+1].f );
        }
    }
}

pii query(int i, int l, int r, int ql, int qr){
    if(ql > r || l > qr) return mp(0, 0);
    else if(ql <= l && r <= qr){
        if(l == r) return mp(l, 0);
        else return nd[i];
    }
    else{
        int mid = (l+r)/2;

        pii left = query(2*i, l, mid, ql, qr), right = query(2*i+1, mid+1, r, ql, qr);

        if(a[ left.f ] < a[ right.f ]){
            if(a[ left.f ] < a[ right.s ] )  return right;
            else return mp(right.f, left.f);
        }
        else{
            if(a[ right.f ] < a[ left.s ]) return left;
            else return mp( left.f, right.f );
        }
    }
}

ll n;

int main(){
	ios::sync_with_stdio(false);

    cin >> n;

    frr(i, n) cin >> a[i];

    int q;
    cin >> q;

    char u;
    ll x, y;

    build(1, 1, n);

    while(q--){
        cin >> u >> x >> y;

        if(u == 'Q'){
            pii e = query(1, 1, n, x, y);

            cout << a[e.f] + a[e.s] << endl;
        }
        else{
            update(1, 1, n, x, y);
        }
    }
}
