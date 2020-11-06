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

int main(){
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	set<ll> div;

	ll i = 1, s = (ll)sqrt(n + .0);

	while(i <= s){
		if(n%i == 0){
			div.insert(i);
			div.insert(n/i);
		}
		i++;
	}

	set<ll> ans;
	for(auto x: div){
		ll t = n/x;

		ans.insert(x*(t - 1)*t/2 + t);
	}

	for(auto x: ans) cout << x << " ";

	cout << endl;
}
