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

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 1000010
#define MOD 1000000007

vector<ll> a, b;

ll v[2][40];

ll mask(int n, int type){
    ll sum = 0;
    int bit = 0;

    while(n > 0){
        sum += v[type][bit]*(n%2);
        n/=2;
        bit++;
    }

    return sum;
}

int main(){
    ios::sync_with_stdio(false);

    int n;
    ll A, B;
    cin >> n >> A >> B;

    fr(i, n/2) cin >> v[0][i];
    fr(i, (n+1)/2) cin >> v[1][i];

    fr(i, (1 << (n/2)) ) a.pb( mask(i, 0) );
    fr(i, (1 << ((n+1)/2) ) ) b.pb( mask(i, 1) );

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

//    cout << a.size() << " " << b.size() << endl;

    ll ans = 0;
    fr(i, a.size()){
        ans -= (ll)(lower_bound(b.begin(), b.end(), A - a[i]) - b.begin() );
        ans += (ll)(lower_bound(b.begin(), b.end(), B + 1 - a[i]) - b.begin() );
    }

    cout << ans << endl;
}
