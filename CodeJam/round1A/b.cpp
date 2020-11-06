/// 
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

vector<pii> ans;

vector<ll> bits(ll n){
	vector<ll> ret;

	while(n > 0){
		ret.pb(n%2);
		n/=2;
	}

	return ret;
}

void build(vector<ll> b){
	ll lado = 0;
	fr(i, b.size()){
		if(lado == 0){
			if(b[i] == 0){
				ans.pb(mp(i, 0));
			}
			else{
				for(ll j = 0; j <= i; j++){
					ans.pb(mp(i, j));
				}

				lado = 1;
			}
		}
		else{
			if(b[i] == 0){
				ans.pb(mp(i, i));
			}
			else{
				for(ll j = i; j >= 0; j--){
					ans.pb(mp(i, j));
				}

				lado = 0;
			}
		}
	}
}

void solve(ll n){
	if(n > 30){
		vector<ll> b = bits(n-30);

		ll num_0s = 0;
		for(ll i = 0; i < b.size(); i++){
			if(b[i] == 0) num_0s++;
		}

		build(b);

		for(ll i = n - 30 + num_0s + 1; i <= n; i++){
			if(ans[ans.size() - 1].s == 0){
				ans.pb(mp(ans[ans.size()-1].f + 1, 0));
			}
			else{
				ans.pb(mp(ans[ans.size()-1].f + 1, ans[ans.size()-1].f + 1));
			}
		}
	}
	else{
		fr(i, n){
			ans.pb(mp(i, i));
		}
	}
}

int main(){
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	frr(ts, t){
		ll n;
		cin >> n;

		ans.clear();

		cout << "Case #" << ts << ": \n";
		solve(n);
		for(auto x: ans){
			cout << x.f + 1 << " " << x.s + 1 << "\n";
		}
	}
}
