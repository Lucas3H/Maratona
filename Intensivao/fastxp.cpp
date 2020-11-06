#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define ll long long

#define MAXN 100010

ll fastxprec(ll base, ll e){
    if(e == 0) return 1;
    ll ans = fastxprec(base, e/2);

    ans *= ans;
    ans = ans%MOD;
    if(e%2 == 1) ans*= base;
    ans = ans%MOD;

    return ans;
}

ll fastxp(ll base, ll e){
    ll ans = 1;

    while(e > 0){
        if(e%2 == 1){
            ans *= base;
            ans = ans&MOD;
        }

        base *= base;
    }

    return ans;
}

int main(){
		ios::sync_with_stdio(false);

}
