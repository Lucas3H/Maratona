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

#define MAXN 1000010
#define MOD 1000000007

ll fac[MAXN];

ll fastxp(ll base, ll e){
  if(e == 1) return base;

  ll ans = fastxp(base, e/2);
  ans*=ans;

  ans %= MOD;
  if(e%2 == 1) ans*=base;
  ans %= MOD;

  return ans;
}

ll bin(ll a, ll b){
  ll ans = (ll)fac[a];
  ll den = fac[b]*fac[a - b];

  den %= MOD;

  ans *= fastxp(den, MOD-2);
  ans%=MOD;

  return ans;
}

bool check(ll n, ll a, ll b){
  while(n > 0){
    if(n%10 != a && n%10 != b) return 0;
    n/=10;
  }

  return 1;
}

int main(){
		ios::sync_with_stdio(false);

    fac[0] = 1;
    frr(i, 1000000){
      fac[i] = fac[i-1]*i;
      fac[i]%=MOD;
    }

    ll a, b, n;
    cin >> a >> b >> n;

    ll ans = 0;
    ll sum = n*a;

    fr(i, n+1){
      if(check(sum, a, b)){
        ans+=bin(n, i);
      }
      sum = sum + b - a;
    }

    cout << (ans+MOD)%MOD << endl;
}
