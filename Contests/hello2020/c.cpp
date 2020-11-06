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

ll fac[250010];

int main(){
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;

	fac[0] = 1;
	frr(i, n){
		fac[i] = (fac[i-1]*(ll)i)%m;
	}

	ll ans = 0;
	fr(i, n){
		ll termo = ((n-i)*fac[n-i])%m;
		termo = (termo*fac[i+1])%m;
		
		ans+=termo;
		ans = ans%m;
	}

	cout << ans << endl;
}
