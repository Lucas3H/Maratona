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
#define INF 987654321

ll u, v;

ll xorr[100], dif[100], n1[100], n2[100];
ll maximo = 0;

void build(ll a, ll b){
	ll i = 0;
	while(a > 0){
		xorr[i] = a%2;
		a/=2;
		i++;
	}
	maximo = max(i, maximo);

	i = 0;
	while(b > 0){
		dif[i] = b%2;
		b/=2;
		i++;
	}

	maximo = max(i, maximo);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> u >> v;

	if(u > v || (u - v)%2 != 0){
		cout << -1 << endl;
		return 0;
	}

	if(v == 0){
		cout << 0 << endl;
		return 0;
	}

	if(u == v){
		cout << 1 << endl;
		cout << u << endl;
		return 0;
	}

	build(u, v - u);

	ll tres = 0;

	fr(i, maximo){
		if(dif[i] == 1){
			if(xorr[i-1] == 1){
				tres = 1;
				n1[i-1] = 1;
				n2[i-1] = 1;
			}
			else{
				xorr[i-1] = 1;
				n1[i-1] = 1;
			}
		}
	}

	ll v[3] = {(ll)0, (ll)0, (ll)0};
	fr(j, maximo){
		if(xorr[j] == (ll)1) v[0] += ((ll)1 << j);
	}
	
	fr(j, maximo){
		if(n1[j]) v[1] += ((ll)1 << j);
	}

	if(tres){
		fr(j, maximo){
			if(n2[j]) v[2] += ((ll)1 << j);
		}
	}

	if(tres){
		cout << 3 << endl;
		fr(i, 3) cout << v[i] << " ";
		cout << endl;
	}
	else{
		cout << 2 << endl;
		cout << v[0] << " " << v[1] << endl;	
	}
}
