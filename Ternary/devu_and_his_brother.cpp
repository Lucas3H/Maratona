#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
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

ll a[MAXN], b[MAXN];
ll n, m;

ll op(ll x){
    ll ans = 0;

    fr(i, n){
        if(a[i] < x) ans+=(x - a[i]);
    }
    fr(i, m){
        if(b[i] > x) ans-=(x - b[i]);
    }

    return ans;
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n >> m;

    fr(i, n) cin >> a[i];
    fr(i, m) cin >> b[i];

    ll l = 1, r = 1000000000;

    while(l < r - 2){
        ll t1 = l + (r - l)/3;
        ll t2 = r - (r - l)/3;

        if(op(t1) > op(t2)) l = t1;
        else r = t2;

    }

    ll ans = op(l);
    for(int i = l + 1; i <= r; i++){
        ans = min(ans, op(i));
    }

    cout << ans << endl;
}
