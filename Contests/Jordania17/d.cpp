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

#define MAXN 7010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

int a[MAXN], odd[1000010];

int main(){
	ios::sync_with_stdio(false);

	freopen("cases.in", "r", stdin);

	int t;
	cin >> t;

	while(t--){
		int ans = 0;

		int n;
		cin >> n;

		frr(i, n) cin >> a[i];

		frr(i, n){
			int o = 0;
			for(int j = i; j <= n; j++) odd[a[j]] = 0;

			for(int j = i; j <= n; j++){
				if(odd[a[j]]) odd[a[j]] = 0, o--;
				else odd[a[j]] = 1, o++;

				if(o == 1) ans++;
			}
		}

		cout << ans << endl;
	}	
}
