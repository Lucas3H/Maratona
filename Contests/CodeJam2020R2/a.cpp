#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int main(){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;

	frr(ts, t){
		ll l, r;
		cin >> l >> r;

		ll i;

		if(l >= r){
			i = (-1 + sqrt(1 + 8*(l-r)))/2;
			l -= ((i+1)*i)/2;
		}
		else{
			i = (-1 + sqrt(1 + 8*(r-l)))/2;
			r -= ((i+1)*i)/2;
		}

		//cout << i << " " << l << " " << r << endl;

		ll k1, k2;

		if(l >= r){
			k1 = (-i + sqrt(i*i + 4*l))/2;
			l -= (k1*k1 + i*k1);

			k2 = (-(i+1) + sqrt((i+1)*(i+1) + 4*r))/2;
			r -= (k2*k2 + k2*(i+1));

			i += max(2*k1 - 1, 2*k2);
		}
		else{
			k1 = (-i + sqrt(i*i + 4*r))/2;
			r -= (k1*k1 + i*k1);

			k2 = (-(i+1) + sqrt((i+1)*(i+1) + 4*l))/2;
			l -= (k2*k2 + k2*(i+1));

			i += max(2*k1 - 1, 2*k2);
		}

		//cout << k1 << " " << k2 << endl;


		cout << "Case #" << ts << ": " << i << " " << l <<  " " << r << "\n";
	}
}
