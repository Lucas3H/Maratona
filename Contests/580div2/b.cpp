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

		ll n;
		cin >> n;

		ll menos = 0, mais = 0;

		ll ans = 0, zero = 0;

		ll a[MAXN];
		fr(i, n){
				cin >> a[i];

				if(a[i] > 0){
					ans += a[i] - 1;
				}
				else if(a[i] == 0){
					zero = 1;
					ans++;
				}
				else{
					ans+=(-1 - a[i]);
					menos++;
				}
		}

		if(zero == 1){
				cout << ans << endl;

		}

		else{
				if(menos%2 == 1) cout << ans+2 << endl;
				else cout << ans << endl;
		}
}
