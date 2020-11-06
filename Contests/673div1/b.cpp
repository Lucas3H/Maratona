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

int n;
int a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		cin >> n;
		int sum = 0, val, deu = 1;

		frr(i, n) {
			cin >> a[i];
			sum += a[i];
		}

		if(sum%n  != 0){
			cout << -1 << endl;
			continue;
		}

		val = sum/n;


		vector<tuple<int,int,int>> ans;

		for(int i = 2; i <= n; i++){
			int q;

			if(a[i]%i != 0){
				ans.pb({1, i, i - a[i]%i});
				a[i] += i - a[i]%i;
			}	

			q = a[i]/i;
			ans.pb({i, 1, q});
			a[i] -= i*q;
		}

		for(int i = 2; i <= n; i++){
		//	cout<< a[i]<< ' ';
			if(a[i] > val){
				deu = 0;
				break;
			}
		}
		//cout << endl;

		if(!deu){
			cout << -1 << endl;
			continue;
		}

		for(int i = 2; i <= n; i++){
			if(a[i] < val);
				ans.pb({1, i, val - a[i]});
		}

		cout << ans.size() << endl;
		for(auto x: ans){
			int a, b, c;
			tie(a, b, c) = x;

			cout << a << " " << b<< ' ' <<c  << endl;
		}
	}
}
