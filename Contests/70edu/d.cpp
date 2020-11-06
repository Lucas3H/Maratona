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
			ll n;
			cin >> n;

			vector<int> aux;

			while(n > 0){
					ll k = floor(sqrt(n*2 + 2));

					while(k*(k-1)/2 > n) k--;
					n-=k*(k-1)/2;

					aux.pb(k);
			}
			aux.pb(0);

			vector<int> ans;
			for(int i = 1; i < aux.size(); i++){
					ans.pb(1);
					for(int j = 1; j <= (aux[i-1] - aux[i]); j++) ans.pb(3);
			}

			ans.pb(7);

			fr(i, ans.size()) cout << ans[i];

			cout << endl;
		}


}
