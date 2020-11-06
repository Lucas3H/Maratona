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
#define INF 987654321

int t, n, k;
int ans = 0;

void build(int x){
	int ind = 0;
	while(x > 0){
		if(x%2 == 1){
			ans = (ans|(1 << ind));
		}
		ind++;
		x/=2;
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("looking.in", "r", stdin);

	cin >> t;

	while(t--){
		cin >> n >> k;
		ans = 0;
		int a[MAXN];
		frr(i, n){
			cin >> a[i];
			build(a[i]);
		}

		cout << ans << endl;
	}
}
