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
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

map<ll, ll> m[11];
int dez[11];
int v[MAXN];

int main(){
	ios::sync_with_stdio(false);

	ll n, k;
	cin >> n >> k;

	dez[0] = 1;
	frr(i, 10) dez[i] = (dez[i-1]*10)%k;

	fr(i, n){
		cin >> v[i];

		//cout << endl << v[i] << endl;

		frr(j, 10){
			m[j][((v[i])%k*(dez[j]))%k]++;
			//cout << j << " " << (v[i]*dez[j])%k << endl;
		}
	}



	ll ans = 0;
	fr(i, n){
		int d = (int)ceil((log(v[i]) + 0.000000000001)/log(10));

		ans += m[d][(k - (v[i])%k)%k];
		
		if(((v[i])%k*dez[d] + v[i]%k)%k == 0) ans--;
		//cout << d << endl;
		//cout << ans << endl;
	}

	cout << ans << endl;
}
