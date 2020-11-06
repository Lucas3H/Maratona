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

int a[MAXN];
int n, m, k;

int func(int l, int r, int rem){

	//cout << l << " " << r << " " << rem << endl;

	int ini = l, fim = r - rem;
	int ans = MOD;

	while(fim <= r){
		ans = min(ans, max(a[ini], a[fim]));
		ini++;
		fim++;
	}

	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){


		cin >> n >> m >> k;

		frr(i, n) cin >> a[i];

		int resp = 0;

		if(k >= m) k = m - 1;

		int ini = 1, fim = n - k;

		while(fim <= n){
			resp = max(resp, func(ini, fim, m - k - 1));
			ini++;
			fim++;
		}

		cout << resp << endl;
	}
}
