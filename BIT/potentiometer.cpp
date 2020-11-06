// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=192

#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
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

ll bit[2*MAXN], v[2*MAXN];
ll n;

void update(ll i, ll val){
    while(i <= n){
        bit[i] += val;
        i += i & (-i);
    }
}

ll query(ll i){
    ll sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= i & (-i);
    }

    return sum;
}

void build(){
    fr(i, n+1) bit[i] = 0;
    frr(i, n) update(i, v[i]);
}

int main(){

    scanf("%lld", &n);
    int t = 1;

    while(n > 0){
        frr(i, n) scanf("%lld", &v[i]);

        build();

        char op[4];
        ll x, y;
        scanf("%s", op);

        printf("Case %d:\n", t++);

        while(op[0] != 'E'){

            scanf("%lld %lld", &x, &y);

            if(op[0] == 'S'){
                update(x, y - v[x]);
                v[x] = y;
            }
            else printf("%lld\n", query(y) - query(x-1));
            scanf("%s", op);
        }
        scanf("%lld", &n);
        if(n > 0) printf("\n");
    }
}
