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

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		int a, b, c;
		cin >> a >> b >> c;

		int ans = 0;

		if(a > 0){
			a--;
			ans++;
		}

		if(b > 0){
			b--;
			ans++;
		}


		if(c > 0){
			c--;
			ans++;
		}

		if(b < c) swap(b, c);
		if(a < b) swap(a, b);
		if(b < c) swap(b, c);

		if(a > 0 && b > 0){
			a--;
			b--;
			ans++;
		}

		if(a > 0 && c > 0){
			a--;
			c--;
			ans++;
		}

		if(c > 0 && b > 0){
			c--;
			b--;
			ans++;
		}

		if(a > 0 && b > 0 && c > 0){
			a--;
			b--;
			c--;
			ans++;
		}

		cout << ans << endl;
	}
}
