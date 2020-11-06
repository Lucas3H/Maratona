// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3809
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

ll b, p, L, n;

ll nd[4*MAXN];

void build(ll i, ll l, ll r){
    if(l == r) nd[i] = (ll)0;
    else{
        nd[i] = (ll)0;
        ll mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
    }
}

ll fastxp(ll base, ll e){
    if(e == 0) return (ll)1;
    ll ans = fastxp(base, e/2);
    ans = (ans*ans)%p;

    if(e%2 == 1) ans = ans*base;

    return ans%p;
}

void update(ll i, ll l, ll r, ll pos, ll v){
    if(l == r) nd[i] = (v*fastxp(b, L - pos))%p;
    else{
        ll mid = (l+r)/2;

        if(pos <= mid) update(2*i, l, mid, pos, v);
        else update(2*i+1, mid+1, r, pos, v);

        nd[i] = (nd[2*i] + nd[2*i+1])%p;
    }
}

ll query(ll i, ll l, ll r, ll ql, ll qr){
    if(ql > r || l > qr) return (ll)0;
    else if(ql <= l && r <= qr) return nd[i];
    else{
        ll mid = (l+r)/2;

        return (query(2*i, l, mid, ql, qr) + query(2*i+1, mid+1, r, ql, qr))%p;
    }
}

int main(){

    char op;
    int x, y;

    scanf("%lld %lld %lld %lld", &b, &p, &L, &n);

    ll cont = 0;

    while(b > 0){

        build((ll)1, (ll)1, L);


        for(int i = 0; i < n; i++){

            scanf(" %c %d %d", &op, &x, &y);

            if(op == 'H') printf("%lld\n", (query((ll)1, (ll)1, L, x, y)*fastxp(b, p-(ll)1 - L + y))%p);

            else update((ll)1, (ll)1, L, x, y);
        }

        printf("-\n");

        scanf("%lld %lld %lld %lld", &b, &p, &L, &n);
    }
}
