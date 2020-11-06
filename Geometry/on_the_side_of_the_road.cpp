// https://www.spoj.com/problems/TAP2013A/
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
typedef pair<ll, ll> ponto;
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

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

ll n;
vector<pair<pii, ll>> road;
ponto p[1010];

void x_intersection(ll a, ll b){
	if(p[b].s < p[a].s) swap(a, b);

	ll dx = (p[b].f - p[a].f), dy = (p[b].s - p[a].s);

	if(dy == 0) return;

	ll num = p[b].f*dy - (dx*p[b].s);

	//cout << num << endl;

	if(num == 0){
		road.pb(mp(mp(0, 1), b));
	}
	else{
		ll d = gcd(num, dy);
		num/=d;
		dy/=d;

		road.pb(mp(mp(num, dy), b));
	}
}

void read(){
	cin >> n;
	fr(i, n) cin >> p[i].f >> p[i].s;
}

bool comp(pair<pii, ll> a, pair<pii, ll> b){
	if(a.f.f*b.f.s == a.f.s*b.f.f) return a.s < b.s;
	else return a.f.f*b.f.s < a.f.s*b.f.f; 
}

int main(){
	ios::sync_with_stdio(false);
	read();
	fr(i, n){
		fr(j, i) x_intersection(i, j);
	}

	sort(road.begin(), road.end(), comp);

	set<ll> ans;
	ll tam = road.size();
	ll i = 0;

	while(i < tam){
		set<ll> not_visible;
		pii val = road[i].f;

		while(i < tam && val.f*road[i].f.s == val.s*road[i].f.f){
			not_visible.insert(road[i].s);
			i++;
		}

		//cout << i << endl;

		ans.insert(n - (ll)not_visible.size());
	}
	
	//fr(i, tam) cout << road[i].f.f <<" " << road[i].f.s <<" " << road[i].s << endl;

	cout << ans.size() + 1 << endl;
}
