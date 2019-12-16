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

double a[20][20];
int n;

int sumbits(int x){
  int ans = 0;
  while(x > 0){
    ans+=x%2;
    x/=2;
  }

  return ans;
}

double p(int x, int y){
  double ans = 0.0;
  fr(i, n){
    if(x%2 == 0) ans += a[i][y];
    x/=2;
  }

  return ans;
}

double dp(int mask, int w){
  int s = sumbits(mask);

//  cout << mask <<" sdaas " << w <<   endl;

  if(s == n-1) return 1.0;

  int m = mask;

  double ans = 0.0;

  s = n-s;

  fr(i, n){
    if(i == w || (m%2) == 1) {
      m/=2;
      continue;
    }
    //cout << "mask " << mask << " " << m << endl;
    //cout << "opoopmkop " << i << " OKO " << (mask|(1 << n)) << endl;

    ans += p(mask, i)*dp((mask|(1 << i)), w)*(double)2/(s*(s-1));
    m/=2;
  }

  //cout << ans << " as "<< w << endl;

  return ans;
}

int main(){
    int tests;
    cin >> tests;
    frr(T, tests){
      cin >> n;

      fr(i, n){
        fr(j, n) cin >> a[i][j];
      }

      cout << "Case "<< T << ": ";

      fr(i, n) printf("%0.6lf ", dp(0, i));
      cout << endl;

    }
}
