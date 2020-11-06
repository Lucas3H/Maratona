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

#define MAXN 200010
#define MOD 1000000007

ll n, m, k, t;
ll a[MAXN];
ll pos_disarm[MAXN];
ll pos_trap[MAXN];
ll danger[MAXN];

set<ll> disarm[MAXN];
set<ll> trap[MAXN];

bool is_possible(ll last_soldier){
	ll min_power = a[last_soldier];
	ll tempo = n+1;

	ll maior_dist = 0;
	ll last_pos = 0;
	frr(i, n){
		for(auto x: trap[i]){
			if(danger[x] > min_power && maior_dist < pos_disarm[x] ){
				maior_dist = max(maior_dist, pos_disarm[x]);
				//cout << x << endl;
			}
		}

		//cout << i << " " << maior_dist << endl;

		if(maior_dist == i) {
			tempo+=2*(maior_dist - last_pos);
			last_pos = i;
		}
		if(maior_dist < i) last_pos = i;
	}
	//cout << maior_dist << endl;


	//cout << last_soldier << " " << tempo << " ";
	if(tempo > t) return 0;
	else return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> m >> n >> k >> t;
	
	frr(i, m) cin >> a[i];
	sort(a+1, a+m+1);

	frr(i, k){
		ll l, r, d;
		cin >> l >> r >> d;

		trap[l].insert(i);
		disarm[r].insert(i);

		pos_trap[i] = l;
		pos_disarm[i] = r;

		danger[i] = d;
	}

	ll l = 1, r = m, mid;
	while(l < r-1){
		mid = (l+r)/2;

		if(!is_possible(mid)) l = mid;
		else r = mid;
	}
	//cout << is_possible(3) << endl;
	//frr(i, m) cout << is_possible(i) << endl;
	if(is_possible(l)) cout << m - l + 1 << endl;
	else if(!is_possible(r)) cout << 0 << endl;
	else cout << m - r + 1 << endl;
}
