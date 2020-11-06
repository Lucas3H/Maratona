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

int satis[20];
int s[20][20];
int n, m, k;
int memo[20][1 << 18];

int sumbits(int x){
  int ans = 0;

  while(x > 0){
    ans+=x%2;
    x/=2;
  }

  return ans;
}

int dp(int dish, int mask){
  if(sumbits(mask) == m) return 0;

  if(dish == n) return 0;
  if(dish > -1 && memo[dish][mask] > -1) return memo[dish][mask];

  int ans = 0;
  for(int i = dish + 1; i < n; i++){
    ans = max(ans, dp(i, mask + (1 << i)) + s[dish][i] + satis[i]);
  }

  return memo[dish][mask] = ans;
}

int main(){
		ios::sync_with_stdio(false);

    mem(memo, -1);

    cin >> n >> m >> k;

    fr(i, n) cin >> satis[i];

    fr(i, k){
      int x, y, c;
      cin >> x >> y >> c;

      s[x][y] = c;
    }

    cout << dp(-1, 0) << endl;

}
