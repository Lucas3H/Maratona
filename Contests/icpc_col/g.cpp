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

int main(){
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;

	ll pares = 1;
	for(ll i = 2; i <= n; i+=2){
		if(i <= 2*m){
			pares = (pares*i/2)%MOD;
		}
		else pares = (pares*i)%MOD;
	}
	
	for(ll i = 1; i <= n; i+=2){
		pares = (pares*i)%MOD;
	}

	fr(i, m){
		int a, b;
		cin >> a >> b;
	}

	cout << pares << endl;
}
