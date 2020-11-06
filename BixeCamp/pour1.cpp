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

int gcd(int a, int b){
  if(b == 0) return a;
  else return gcd(b, a%b);
}

int main(){
		ios::sync_with_stdio(false);

    int q;
    cin >> q;

    while(q--){
      int a, b, c;

      cin >> a >> b >> c;

      if(a < b) swap(a, b);

      int d = gcd(a, b);
      if(c%d != 0 || c > a) cout << -1 << endl;
      else{
        int i = 1, j = 1;

        while((a*i)%b != c%b) i++;
        while((b*j)%a != c%a) j++;

        int q1 = (a*i - c)/b, q2 = (b*j - c)/a;

        int ans1 = 0, va = 0, vb = 0;
        for(int k = 0; k < i && va != c && vb != c; k++){
          va = a;
          ans1++;
//          cout << va << " "<< vb << " " << ans1 << endl;

          while(va > 0 && va != c && vb != c){
            int A = va, B = vb;

            va -= min(b - B, A);
            vb += min(b - B, A);
            ans1++;
//            cout << va << " "<< vb << " " << ans1 << endl;

            if(va == c) break;
            if(vb == c) break;

            if(vb == b){
              vb = 0;
              ans1++;
//              cout << va << " "<< vb << " " << ans1 << endl;
            }
          }

        }

        int ans2 = 0;
        va = 0, vb = 0;
        for(int k = 0; k < j && va != c && vb != c; k++){
          vb = b;
          ans2++;

          while(vb > 0 && va != c && vb != c){
            int A = va, B = vb;

            vb -= min(a - A, B);
            va += min(a - A, B);

            ans2++;

            if(vb == c) break;
            if(va == c) break;
            if(va == a){
              va = 0;
              ans2++;
            }
          }
        }

        cout << min(ans1, ans2) << endl;
      }

    }
}
