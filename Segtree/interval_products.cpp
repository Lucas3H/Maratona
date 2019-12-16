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

int n, k;
int nd[4*MAXN], a[MAXN];

void build(int i, int l, int r){
    if(l == r){
        if(a[l] > 0) nd[i] = 1;
        else if(a[l] < 0) nd[i] = -1;
        else nd[i] = 0;
    }
    else{
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);

        nd[i] = nd[2*i]*nd[2*i+1];
    }
}

void update(int i, int l, int r, int pos, int val){
    if(l == r){
        if(val > 0) nd[i] = 1;
        else if(val < 0) nd[i] = -1;
        else nd[i] = 0;
    }
    else{
        int mid = (l+r)/2;

        if(pos > mid) update(2*i+1, mid+1, r, pos, val);
        else update(2*i, l, mid, pos, val);

        nd[i] = nd[2*i]*nd[2*i+1];
    }
}

int query(int i, int l, int r, int ql, int qr){
    if(r < ql || qr < l) return 1;
    else if(ql <= l && r <= qr) return nd[i];
    else{
        int mid = (l+r)/2;

        int c = query(2*i, l, mid, ql, qr);
        int b = query(2*i + 1, mid+1, r, ql, qr);

        return c*b;
    }
}

int main(){
	ios::sync_with_stdio(false);

    while(cin >> n >> k){
        frr(i, n) cin >> a[i];
        build(1, 1, n);

        char op;
        int c, b;
        while(k--){
            cin >> op >> c >> b;

            if(op == 'C') update(1, 1, n, c, b);
            else{
                int q = query(1, 1, n, c, b);

                if(q > 0) cout << '+';
                else if(q == 0) cout << '0';
                else cout << '-';
            }
        }

        cout << endl;
    }
}
