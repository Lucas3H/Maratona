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
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

pii v2(int n){
	int ans = 0;

	while(n%2 == 0){
		n/=2;
		ans++;
	}

	return mp(n, ans);
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		map<int, int> m;

		fr(i, n){
			int x;
			cin >> x;

			pii k = v2(x);

			m[k.f] = max(m[k.f], k.s);
		}

		int ans = 0;

		for(auto x: m){
			ans += x.s;
		}
		
		cout << ans << endl;
	}
}
