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

int nd[4*MAXN];
int pt[MAXN];

void build(int i, int l, int r){
    if(l == r) nd[i] = pt[l];
    else{
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);

        nd[i] = min(nd[2*i], nd[2*i+1]);
    }
}


int query(int i, int l, int r, int ql, int qr){
    if(ql > r || l > qr) return MOD;
    else if(ql <= l && r <= qr) return nd[i];
    else{
        int mid = (l+r)/2;

        int a = query(2*i, l, mid, ql, qr), b = query(2*i+1, mid+1, r, ql, qr);

        return min(a, b);
    }
}

int main(){
	ios::sync_with_stdio(false);

    int T;
    cin >> T;

    frr(j, T){
        int n, q;
        cin >> n >> q;
        frr(i, n) cin >> pt[i];

        build(1, 1, n);

        cout << "Scenario #" << j << ":" << endl;
        while(q--){
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << endl;
        }


    }
}
