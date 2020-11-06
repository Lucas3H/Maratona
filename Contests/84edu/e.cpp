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

#define MAXN 200010
#define MOD 998244353
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll n;
ll dez[MAXN];

int main(){
	cin >> n;

	dez[0] = 1;
	frr(i, n){
		dez[i] = (10*dez[i-1])%MOD;
	}

	frr(k, n){
		if(k == n) cout << 10 << " ";
		else{
			ll ans = (2*9*dez[n-k-1])%MOD;
			
			if(k < n-1) ans = (ans + (n-k-1)*81*dez[n-k-2])%MOD;
			ans = (10*ans)%MOD;
		
			cout << ans << " ";
		}
	}

	cout << endl;
}
