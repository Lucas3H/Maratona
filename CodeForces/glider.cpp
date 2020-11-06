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

ll n, h;

int main(){
		ios::sync_with_stdio(false);

    cin >> n >> h;

    ll ini[2*MAXN], fim[2*MAXN];

    fr(i, n) cin >> ini[i] >> fim[i];

    ll descended = 0, j = 0, ans;

    fr(i, n){
			//cout << i << endl;
			//cout << "Antes " << descended << " " << j << endl;

      while(descended < h && j < n-1){
        descended += (ini[j+1] - fim[j]);
        j++;
      }

      if(descended >= h){
				j--;
        descended -= (ini[j+1] - fim[j]);
      }

			//cout << "Depois " << descended << " " << j << endl << endl;

      if(ans < (fim[j] - ini[i]) + (h - descended)) ans = (fim[j] - ini[i]) + (h - descended);

			descended -= ini[i+1] - fim[i];
		}

    cout << ans << endl;
}
