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

ll m[30][30];
ll fr[30];
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;

	fr(i, s.size()){
		ll ind = s[i] - 'a';

		fr(j, 26){
			m[ind][j] += fr[j];
		}

		fr[ind]++;
	}

	ll ans = 0;
	fr(i, 26){
		fr(j, 26){
			ans = max(ans, m[i][j]);
		}
	}	

	fr(i, 26){
		ans = max(ans, fr[i]);
	}

	cout << ans << endl;
}
