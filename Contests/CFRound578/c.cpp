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

ll gcd(ll a, ll b){
		if(b == 0) return a;
		else return gcd(b, a%b);
}

int main(){
		ios::sync_with_stdio(false);

	 	ll n, m, q;
		cin >> n >> m >> q;

		ll d = gcd(n, m);

		n/=d;
		m/=d;

		while(q--){
				ll a, b, c, d;
				cin >> a>> b >> c >> d;

				b--;
				d--;

				if(a == 1){
						b = b/n;
				}
				else b = b/m;
				if(c == 1){
						d = d/n;
				}
				else d = d/m;

				if(b == d) cout << "YES" << endl;
				else cout << "NO" << endl;
		}
}
