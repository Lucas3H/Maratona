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

ll mdc(ll a, ll b){
  if(b == 0) return a;
  else return mdc(b, a%b);
}

void EuclideanExtended(ll a, ll b, ll *x, ll *y){
  if(b == 0){
    *x = 1;
    *y = 0;
    return;
  }

  ll x0, y0;
  EuclideanExtended(b, a%b, &x0, &y0);

  *x = y0;
  *y = x0 - (a/b)*y0;
}

int main(){
		ios::sync_with_stdio(false);

    ll n, n1, n2, c1, c2;
    cin >> n;
    while(n > 0){
      cin >> c1 >> n1 >> c2 >> n2;

      ll d = mdc(n1, n2);

      ll x, y;
      EuclideanExtended(n1, n2, &x, &y);

      x *= (n/d);
      y *= (n/d);


      ll D = mdc(n1, n2);
      ll a = n1/D, b = n2/D;


      if(n%d != 0){
        cout << "failed\n";
      }
      else if(n1*c2 > c1*n2){
        if(y < 0){
          ll w = (-y-1)/a + 1;

          if(x/b >= w){
            cout << x - b*w << " " << a*w + y << endl;
          }
          else cout << "failed\n";
        }
        else{
          ll w = y/a;

          if(w >= (-x-1)/b + 1){
            cout << x + b*w << " " << y - a*w << endl;
          }
          else cout << "failed\n";
        }
      }
      else{
        if(x < 0){
          ll w = (-x-1)/b + 1;

          if(w <= y/a){
            cout << x + w*b << " " << y - a*w << endl;
          }
          else cout << "failed\n";
        }
        else{
          ll w = x/b;

          if(w >= (-y-1)/a + 1){
            cout << x - b*w << " " << a*w + y << endl;
          }
          else{
            cout << "failed\n";
          }
        }
      }

      cin >> n;

    }
}
