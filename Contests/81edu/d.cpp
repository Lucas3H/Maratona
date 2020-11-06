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

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

vector<ll> p;
ll is_prime[MAXN];

void crivo(){
	for(int i = 2; i < MAXN; i++){
		if(!is_prime[i]){
			p.pb(i);

			for(int j = 2*i; j < MAXN; j += i){
				is_prime[j] = 1;
			}
		}
	}
}

ll phi(ll x){
	ll aux = x;

	int it = 0;
	while(aux > 1 && it < p.size()){
		if(aux%p[it] == 0){
			x /= p[it];
			x *= p[it] - 1;

			while(aux%p[it] == 0) aux /= p[it];
		}

		it++;
	}

	if(aux > 1){
		x /= aux;
		x *= aux - 1;
	}

	return x;
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	crivo();


	while(t--){
		ll a, m;

		cin >> a >> m;

		ll d = gcd(a, m);

		a /= d;
		m /= d;

		cout << phi(m) << endl;
	}
}
