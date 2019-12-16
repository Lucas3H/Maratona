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
		int t;
		cin >> t;

		while(t--){
			ll n, k;
			cin >> n >> k;

			ll ans = 0;
			while(n > 0){
				if(n%k == 0){
					n/=k;
					ans++;
				}
				else{
					ans += (n%k);
					n-=(n%k);
				}
			}

			cout << ans << endl;
		}
}
