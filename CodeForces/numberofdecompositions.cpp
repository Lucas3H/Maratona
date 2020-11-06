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

ll fac[MAXN];

ll fastxp(ll base, ll e){
  if(e == 1) return base;

  ll ans = fastxp(base, e/2);
  ans*=ans;
  ans%=MOD;

  if(e%2 == 1) ans*=base;
  ans%=MOD;

  return ans;
}

ll bin(ll a, ll b){
  ll ans = fac[a];
  ll den = (fac[b]*fac[a-b])%MOD;

  ans *= fastxp(den, MOD-2);

  ans%=MOD;

  return MOD;
}

int prime[MAXN], expo[MAXN];
vector<int> p;

void dec(int n){
  int i = 0;
  while(n > 1){
    while(n%p[i] == 0){
      n/=p[i];
      expo[i]++;
    }

    i++;
  }
}

int main(){
		ios::sync_with_stdio(false);

    fac[0] = 1;
    frr(i, MAXN - 1) fac[i] = (i*fac[i-1])%MOD;

    for(int i = 2; i < MAXN; i++){
      if(prime[i] == 0){
        p.pb(i);
        for(int j = 2*i; j < MAXN; j += i)prime[j] = 1;
      }
    }

    int n;
    cin >> n;

    int x;
    fr(i, n){
      cin >> x;
      dec(x);
    }

    ll ans = 0;
    fr(i, MAXN){
      ans += bin(n+expo[i] - 1, n);
      ans %= MOD;
    }

    cout << ans << endl;
}
