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

#define MAXN 100000
#define MOD 1000000007

int main(){
		ios::sync_with_stdio(false);

    int q;
    cin >> q;

    while(q--){
      int n;
      cin >> n;

      int xl = -MAXN, xr = MAXN;
      int yu = MAXN, yd = -MAXN;

      int x, y, f1, f2, f3, f4;

      fr(i, n){
        cin >> x >> y >> f1 >> f2 >> f3 >> f4;

        if(f1 == 0) xl = max(xl, x);
        if(f2 == 0) yu = min(yu, y);
        if(f3 == 0) xr = min(xr2, x);
        if(f4 == 0) yd = max(yd, y);
      }

      if(xr < xl || yu < yd) cout << 0 << endl;
      else cout << 1 << " " << xr << " " << yu << endl;
    }

    return 0;
}
