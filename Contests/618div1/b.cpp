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

pii reflexo(pii a, pii b){
	ll dx = b.f - a.f, dy = b.s - a.s;

	return mp(b.f + dx, b.s + dy);
}

int main(){
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	map<ll, set<ll>> m;
	pii list[MAXN];

	ll mx = 0, my = 0;

	frr(i, n){
		cin >> list[i].f >> list[i].s;

		mx += list[i].f;
		my += list[i].s;

		m[list[i].f].insert(list[i].s);
	}

	//cout << mx << " " << my << endl;

	int deu = 1;
	frr(i, n){
		if((2*mx - n*list[i].f)%n != 0 || (2*my - n*list[i].s)%n != 0){
			deu = 0;
			break;
		}

		ll x = (2*mx - n*list[i].f)/n, y = (2*my - n*list[i].s)/n;
/*
		cout << list[i].f << " " << list[i].s << endl;
		cout << x << " " << y << endl;
*/
		if(m[x].find(y) == m[x].end()){
			deu = 0;
			break;
		}
	}

	if(deu) cout << "YES\n";
	else cout << "NO\n";


}
