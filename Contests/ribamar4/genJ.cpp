#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
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
#define INF 1000000000000000000

int main(){
	ios::sync_with_stdio(false);
	ll seed;
	cin >> seed;
	srand(seed);

	ll n = 200000, q = 200000;
	cout << n << " "<< q << "\n";

	frr(i, n){
		cout << rand()%INF + 1 << " ";
	}

	cout << "\n";

	frr(i, q){
		ll v = rand()%INF + 1;
		ll a = rand()%n + 1;
		ll b = rand()%n + 1;	

		if(a > b) swap(a, b);
		cout << v <<" " << a<< " " << b << "\n";
	}
}
