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

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll n, a[MAXN], t[MAXN];

vector<pii> line;
pq<ll> preco;
ll soma = 0, ans;

bool comp(pii a, pii b){
	if(a.f == b.f) return a.s > b.s;
	else return a.f < b.f;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;

	frr(i, n) cin >> a[i];
	frr(i, n) cin >> t[i];

	frr(i, n){
		line.pb(mp(a[i], t[i]));
	}

	sort(line.begin(), line.end(), comp);

	preco.push(line[0].s);
	soma += line[0].s;

	//cout << soma << endl;

	frr(i, n - 1){
		ll it = 0;

		while(preco.empty() == 0 && it < line[i].f - line[i-1].f){
			//cout << preco.top() << endl;
			soma-=preco.top();
			preco.pop();
			
			ans += soma; 

			//cout << ans << " " << soma << endl;

			it++;
		}

		preco.push(line[i].s);
		soma += line[i].s;
	}

	while(preco.empty() == 0 ){
		soma-=preco.top();
		preco.pop();
			
		ans += soma; 
	}

	cout << ans << endl;
}
