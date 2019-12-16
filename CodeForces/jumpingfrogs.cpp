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
    string s;
    int rocks[MAXN];

    while(cin >> s){
      int n = s.size();

      fr(i, s.size()){
        if(s[i] == 'P') rock[i] = 0;
        else rock[i] = 1;
      }

      vector<int> divisors;

      frr(i, n-1){
        if(n%i == 0) divisors.pb(i);
      }

      int ans = 0;
      fr(i, divisors.size()){
        int d = divisors[i];

        int deu = 0;

        fr(j, d){
          int rocks = 0;

          fr(k, n/d){
            if(rock[(j + k*d)%n] == 0) break;
            rocks++;
          }

          if(rocks == n/d){
            deu = 1;
            break;
          }
        }

        if(deu) ans++;
      }

      cout << ans << endl;
    }
}
