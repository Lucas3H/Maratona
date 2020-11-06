#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef pair<int,int> pii;
#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define ll long long
#define MAXN 100010

ll lz[4*MAXN], s[4*MAXN], v[MAXN];

void build(int i, int l, int r){
    if(l == r) s[i] = v[l];
    else{
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);

        s[i] = s[2*i] + s[2*i+1];
    }
}

void push(int i, int l, int r){
    if(lz[i] == -1) return;

    s[i] = (r - l + 1)*lz[i];

    if(l < r){
        lz[2*i] = lz[i];
        lz[2*i+1] = lz[i];
    }

    lz[i] = -1;
}

void update(int i, int l, int r, int ql, int qr, int k){
    push(i, l, r);

    if(ql <= l && r <= qr){
        lz[i] = k;
		push(i, l, r);
        return;
    }
    else if(ql > r || l > qr){
        return;
    }
    else{
        int mid = (l+r)/2;

        update(2*i, l, mid, ql, qr, k);
        update(2*i+1, mid+1, r, ql, qr, k);

        s[i] = s[2*i] + s[2*i+1];

        return;
    }
}

ll query(int i, int l, int r, int ql, int qr){
    push(i, l, r);

    if(ql <= l && r <= qr) return s[i];
    else if(ql > r || l > qr) return 0;
    else{
        int mid = (l +r)/2;
        return query(2*i, l, mid, ql, qr) + query(2*i+1, mid+1, r, ql, qr);
    }
}

int main(){
		ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

	mem(lz, -1);

    frr(i, n) cin >> v[i];

    build(1, 1, n);

    int o, a, b, k;
    while(q--){
        cin >> o;

        if(o == 1){
            cin >> a >> b >> k;

            update(1, 1, n, a, b, k);
        }
        else{
            cin >> a >> b;

            cout << query(1, 1, n, a, b) << endl;
        }
    }

    return 0;
}
