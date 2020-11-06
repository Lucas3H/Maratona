// 
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
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

vector<ll> digits(ll n){
	vector<ll> v;
	while(n > 0){
		v.pb(n%10);
		n/=10;
	}

	return v;
}

vector<ll> solve(vector<ll> n){
	if(n.size() == 1) return n;
	vector<ll> ans;
	ll tam = n.size();
	ll primeiro = n[tam - 1];
	n.pop_back();

	ans = solve(n);

	if(ans[tam - 2] < primeiro){
		primeiro--;
		ans.clear();

		fr(i, tam - 1){
			ans.pb(9);
		}
	}

	ans.pb(primeiro);

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	frr(ts, t){
		ll n;
		cin >> n;

		vector<ll> ans = solve(digits(n));

		cout << "Case #" << ts << ": ";

		if(ans[ans.size() - 1] == 0) 
			ans.pop_back();

		frm(i, ans.size())
			cout << ans[i];

		cout << endl;
	}
}
