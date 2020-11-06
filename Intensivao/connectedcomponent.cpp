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

int main(){
		ios::sync_with_stdio(false);

    int q;
    cin >> q;

    while(q--){
      int b, w;
      cin >> b >> w;

      if(w <= b + 1 + 2*b && b <= 3*w + 1){
        cout << YES << endl;

        if(b >= w){
          fr(i, b+w){
            cout << 2 << " " << i+1 << endl;
          }

          b-=w;

          if(b > 0){
            cout << 2 << " " << b + w + 1 << endl;
            b--;
          }

          int j = 2;
          while(b > 0){
            cout << 1 << " " << j << endl;
            b--;

            if(b == 0) break;

            cout << 3 << " " << j << endl;
            b--;

            j+=2;
          }
        }

        if(b < w){
          fr(i, b+w+1){
            cout << 3 << " " << i+1 << endl;
          }

          w-=(b+1);

          int j = 2;
          while(w > 0){
            cout << 2 << " " << j << endl;
            w--;

            if(w == 0) break;

            cout << 4 << " " << j << endl;
            w--;

            j+=2;
          }
        }
      }
    }
}
