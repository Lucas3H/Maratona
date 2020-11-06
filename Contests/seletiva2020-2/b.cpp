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

ll x, y, a, b, c;

ll r[MAXN], g[MAXN];
ll ans = 0;
pq<ll> notColor;
pq<ll, vector<ll>, greater<ll>> chosen;

void build(){
	cin >> x >> y >> a >> b >> c;

	frr(i, a){
		cin >> r[i];
	}

	sort(r + 1, r + a + 1);

	for(ll j = a; j > a - x; j--){
		chosen.push(r[j]);
		ans+=r[j];
	}


	frr(i, b){
		cin >> g[i];
	}

	sort(g + 1, g + b + 1);

	for(ll j = b; j > b - y; j--){
		chosen.push(g[j]);
		ans+=g[j];
	}

	fr(i, c){
		ll aux;
		cin >> aux;
		notColor.push(aux);
	}
}

void solve(){
	while(!notColor.empty() && notColor.top() > chosen.top()){
		ans-=chosen.top();
		chosen.pop();
		ans+=notColor.top();
		chosen.push(notColor.top());
		notColor.pop();
	}
}

int main(){
	ios::sync_with_stdio(false);
	build();
	solve();

	cout << ans << endl;
}
