#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define fs first
#define sc second

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

ll a[MAXN];
ll pos[MAXN];
ll prod[MAXN];
ll n;

int main(){
	ios::sync_with_stdio(false);

    cin >> n;
    prod[0] = 1;

    frr(i, n) {
        cin >> a[i];

        if(a[i]*prod[i-1] > 0){
            prod[i] = 1;
            pos[i] = pos[i-1] + 1;
        }
        else {
            prod[i] = -1;
            pos[i] = pos[i-1];
        }
    }

    ll ans = 0;

    fr(i, n+1){
        if(prod[i] > 0){
            ans += (pos[n] - pos[i]);
        }
        else ans += (n - pos[n] - i + pos[i]);
    }

    cout << n*(n-1)/2 + n - ans << " " << ans << endl;
}
