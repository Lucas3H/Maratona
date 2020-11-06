#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll, ll> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

ll n, q;
ll v[2*MAXN];
ll bit[2*MAXN][2];
ll pot;

void update(ll i, ll vl, ll t){
    while(i <= n){
        bit[i][0] += vl;
        bit[i][1] += t;
        i+=i&(-i);
    }
}

ll query(ll i, ll t){
    ll sum = 0;
    while(i > 0){
        sum += bit[i][t];
        i-=i&(-i);
    }

    return sum;
}
/*
ll bb(ll vl){
    ll i = pot;
    ll ans = 0;

    while(i >= 0 && vl >= 0){
        if(ans + (1 << i) > n){
            i--;
            continue;
        }

        if(bit[ans + (1 << i)][1] <= vl){
            ans += (1 << i);
            vl -= bit[ans][1];
        }

        i--;
    }

    return ans;
}
*/
multiset<ll> m;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%lld", &n);

        m.clear();

        frr(i, n){
            bit[i][0] = 0;
            bit[i][1] = 0;
        }

        frr(i, n) {
            update(i, i, (ll)1);
            v[i] = i;
            m.insert(i);
        }

        pot = 0;
        while(((ll)1 << pot) <= n) pot++;
        pot--;

        scanf("%lld", &q);

        while(q--){
            int op;
            scanf("%d", &op);

            if(op == 1){
                ll i, k;
                scanf("%lld %lld", &i, &k);

                m.erase( m.find(v[i]) );
                m.insert(k);

                update(v[i], -v[i], -(ll)1);
                v[i] = k;
                update(v[i], v[i], (ll)1);
            }
            else{
                ll ini = *(m.begin());
                ll fim = *(m.rbegin());

                ll meio = (ini + fim)/2;

                //cout << ini << " " << fim << endl;
                //cout << query(meio, 0) << " " << query(meio, 1) << " " << query(fim, 0) << endl;

                printf("%lld\n", query(meio, (ll)1)*(fim + ini) - 2*query(meio, (ll)0) + query(fim, (ll)0) - n*ini - fim + ini);
            }
/*
            frr(i, n) cout << query(i, 0) << " ";
            cout << endl;
            frr(i, n) cout << query(i, 1) << " ";
*/
      }
    }
}
