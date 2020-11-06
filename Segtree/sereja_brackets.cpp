// https://codeforces.com/problemset/problem/380/C

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

#define MAXN 1000010
#define MOD 1000000007

pii nd[4*MAXN];
int a[4*MAXN];
string s;
int ans = 0;

void build(int i, int l, int r){
    if(l == r){
        if(s[l-1] == ')') nd[i] = mp(1, 0);
        else nd[i] = mp(0, 1);
    }
    else{
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);

        a[i] = a[2*i] + a[2*i+1];
        int minimo = min(nd[2*i].s, nd[2*i+1].f);
        a[i] += minimo;

        nd[i] = mp(nd[2*i].f + nd[2*i+1].f - minimo, nd[2*i].s + nd[2*i+1].s - minimo);
    }
}

pii query(int i, int l, int r, int ql, int qr){

    if(ql > r || l > qr) return mp(0, 0);
    else if(ql <= l && r <= qr) {
        ans += a[i];
        return nd[i];
    }
    else{
        int mid = (l+r)/2;

        pii left = query(2*i, l, mid, ql, qr);
        pii right = query(2*i+1, mid+1, r, ql, qr);

        int minimo = min(left.s, right.f);
        ans += minimo;

        return mp(left.f + right.f - minimo, left.s + right.s - minimo);
    }
}

int main(){
	ios::sync_with_stdio(false);

    cin >> s;

    int q;
    cin >> q;

    build(1, 1, s.size());

    int l, r;
    while(q--){
        cin >> l >> r;

        ans = 0;

        pii q = query(1, 1, s.size(), l, r);

        cout << 2*ans << endl;
    }
}
