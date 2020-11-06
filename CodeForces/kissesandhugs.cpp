#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

ll fastxp(ll base, ll e){
    ll ans = 1;

    while(e > 0){
        if(e%2 == 1) {
            ans*=base;
            mod(ans, MOD);
        }
        base*=base;
    }

    return ans;
}

int main(){
		ios::sync_with_stdio(false);

    int t;
    cin>> t;
    while(t--){
        ll n;
        cin >> n;

        if(n%2==1){
            cout << (fastxp(2, (n+3)/2) - 2 + MOD)%MOD << endl;
        }
        else{
            cout << (3*fastxp(2, n/2) - 2 + MOD)%MOD << endl;
        }
    }

    return 0;
}
