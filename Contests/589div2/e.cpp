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

#define MAXN 300010
#define MOD 1000000007

ll bin(int n, int k){
    if(k == 0) return 1;
    ll ans = bin(n-1, k-1)*n/k;
    return ans;
}

ll fastxprec(ll base, ll e){
    if(e == 0) return 1;
    ll ans = fastxprec(base, e/2);

    ans *= ans;
    ans = ans%MOD;
    if(e%2 == 1) ans*= base;
    ans = ans%MOD;

    return ans;
}

int main(){
    ll ans = 0;

    int n, k;
    cin >> n >> k;

    if(k == 1){
        cout << 1 << endl;
        return 0;
    }

    for(int i = n; i <= n*n; i++){
        ll a = 1;

        a*=bin(i-1, n-1);
        a = a%MOD;

        a*=bin(i-1, n-1);
        a = a%MOD;


        a *= fastxprec(k-1, n*n - i);
        a = a%MOD;

        cout << a << endl;

        ans+=a;
    }

    cout << ans << endl;
}
