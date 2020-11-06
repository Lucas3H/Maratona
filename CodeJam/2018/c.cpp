// 
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

ll n, k;

void solve(){

	ll ans;

	ll qt = 1;

	while(n%2 == 1 && k > 0){
		k -= qt;
		qt *= 2;

		n /= 2;
	}

	if(k <= 0){
		cout << n << " " << n << endl;

		return;
	}

	k -= qt;

	if(0 >= k){
		ans = n;
		cout << (ans)/2 << " " << (ans - 1)/2 << endl;

		return;
	}
	ll n1 = (n-1)/2, n2 = n/2;
	ll q1 = qt, q2 = qt;

	qt *= 2;

	while(true){
		//cout << n1 << ' ' << n2 << " " << q1 << " " << q2 << endl;
		if(qt >= k){
			if(k > q2)
				ans = n1;
			else
				ans = n2;

			break;
		}

		if(n1%2 == 0)
			q2 = q1 + 2*q2;
		else
			q1 = 2*q1 + q2;

		k -= qt;
		n2 = n2/2;
		n1 = (n1 - 1)/2;

		qt *= 2;
	}

	cout << (ans)/2 << " " << (ans - 1)/2 << endl;
}

int main(){
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	frr(ts, t){
		cin >> n >> k;

		cout << "Case #" << ts << ": ";

		solve();
	}
}
