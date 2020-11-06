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
typedef pair<ll, ll> pll;
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

ll n;
ll h[MAXN];

ll l[MAXN], r[MAXN];
stack<ll> s;
ll ans[MAXN];

void read(){
	cin >> n;

	frr(i, n) cin >> h[i];
}

int main(){
	ios::sync_with_stdio(false);

	read();

	frr(i, n){
		while(!s.empty() && h[s.top()] < h[i])
			s.pop();

		if(s.empty())
			l[i] = i, s.push(i);
		else if(h[s.top()] == h[i])
			if(l[s.top()] == s.top()) l[i] = i;
			else l[i] = l[s.top()];
		else
			l[i] = s.top(), s.push(i);
	}
/*
	frr(i, n){
		cout << l[i] <<' ';
	}

	cout << endl;
*/
	while(!s.empty()) s.pop();

	for(ll i = n; i > 0; i--){
		while(!s.empty() && h[s.top()] < h[i])
			s.pop();

		if(s.empty())
			r[i] = i, s.push(i);
		else if(h[s.top()] == h[i]){
			if(r[s.top()] == s.top()) r[i] = i;
			else r[i] = r[s.top()];
		}
		else
			r[i] = s.top(), s.push(i);
	}

/*
	frr(i, n){
		cout << r[i] <<' ';
	}

	cout << endl;
*/
	vector<pii> p;
	frr(i, n) p.pb({h[i], i});

	sort(p.begin(), p.end());
	frm(i, n){
		ll x = p[i].s;
		ans[x] = max(ans[l[x]] + x - l[x], ans[r[x]] + r[x] - x);
	}

	frr(i, n) cout << ans[i] <<' ';
	cout << endl;
}
