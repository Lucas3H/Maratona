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
#define INF 1000000000000000100

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		map<int, int> m;
		int n;
		cin >> n;

		vector<int> pos, neg;
		int a[100], sp = 0, sn = 0, zero = 0;
		frr(i, n) {
			cin >> a[i];
			if(a[i] < 0){
				sn-=a[i];
				neg.pb(a[i]);
			}
			else if(a[i] > 0){
				sp+=a[i];
				pos.pb(a[i]);	
			}
			else{
				zero++;
			}
		}

		if(sp == sn){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";

		if(sp > sn){
			for(auto x: pos) cout << x << " ";
			for(auto x: neg) cout << x << " ";
			fr(i, zero) cout << 0 << " ";
			cout << endl;
		}
		else{
			for(auto x: neg) cout << x << " ";
			for(auto x: pos) cout << x << " ";
			fr(i, zero) cout << 0 << " ";
			cout << endl;
		}
	}
}
