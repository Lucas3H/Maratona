#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 10010
#define MOD 1000000007

ll h[MAXN], c[MAXN];
pii b[MAXN];

int main(){
	ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        frr(i, n) cin >> h[i];
        frr(i, n) cin >> c[i];

        frr(i, n) b[i] = mp(h[i], c[i]);
        sort(b + 1, b + n + 1);

        ll sumHC[MAXN], sumC[MAXN];

        sumHC[0] = 0;
        sumC[0] = 0;

        frr(i, n){
            sumHC[i] = sumHC[i-1] + b[i].f*b[i].s;
            sumC[i] = sumC[i-1] + b[i].s;
        }

        ll ans = sumHC[n];

        frr(i, n){

            ans = min(ans, b[i].f*sumC[i] - sumHC[i] - (sumC[n] - sumC[i])*b[i].f + sumHC[n] - sumHC[i]);
        }

        cout << ans << endl;
    }
}
