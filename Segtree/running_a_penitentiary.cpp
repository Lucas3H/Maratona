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

#define MAXN 200010
#define MOD 1000000007

pii nd[4*MAXN];
pii v[MAXN];

pii junta(pii a, pii b){
    int k = max(a.first, b.first);
    int l = min(a.second, b.second);

    return mp(k, l);
}

void build(int i, int l, int r){
    if(l == r) nd[i] = v[l];
    else{
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);

        nd[i] = junta(nd[2*i], nd[2*i+1]);
    }
}

void update(int i, int l, int r, int g, int ql, int qr){
    if(l == r) nd[i] = mp(ql, qr);
    else{
        int mid = (l+r)/2;

        if(g <= mid) update(2*i, l, mid, g, ql, qr);
        else update(2*i+1, mid+1, r, g, ql, qr);

        nd[i] = junta(nd[2*i], nd[2*i+1]);
    }
}

pii query(int i, int l, int r, int ql, int qr){
    if(r < ql || qr < l) return mp(-MOD, MOD);
    else if(ql <= l && r <= qr) return nd[i];
    else{
        int mid = (l+r)/2;

        return junta(query(2*i, l, mid, ql, qr), query(2*i+1, mid+1, r, ql, qr));
    }
}

int main(){
	ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    int v1, v2;
    frr(i, n){
        cin >> v1 >> v2;
        v[i] = mp(v1, v2);
    }

    build(1, 1, n);

    while(q--){
        char op;
        int a, b, c;
        cin >> op >> a >> b;

        if(op == '?') {
            pii ans = query(1, 1, n, a, b);
            cout << max(0, ans.second - ans.first + 1) << endl;
        }
        else{
            cin >> c;
            update(1, 1, n, a, b, c);
        }
    }
}
