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

int h[MAXN];

int main(){
		ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
      int n, k;
      cin >> n >> k;

      vector<int> v;

      fr(i, n) cin >> h[i];

      for(int i = 0; i < k + 2 && i < n; i++) v.pb(h[i]);
      sort(v.begin(), v.end());

      int maximo = v[min(k+1, n-1)] - v[0];

      for(int i = k + 2; i < n; i++){
        auto j = lower_bound(v.begin(), v.end(), h[i - k - 2]) - v.begin();

        v.erase(v.begin() + j, v.begin() + j + 1);

        j = lower_bound(v.begin(), v.end(), h[i]) - v.begin();

        v.insert(v.begin() + j, h[i]);

        maximo = max(maximo, v[k+1] - v[0]);

				//cout << maximo << " " << i << endl;
      }

      cout << maximo << endl;
    }
}
