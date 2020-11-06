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
typedef pair<ll, ll> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 998244353
#define MAXL 30
#define ROOT 1

int main(){
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;

	ll sub = 0;
	ll termo = n;

	fr(i, n-1){
		sub = (sub + termo)%MOD;
		termo=(termo*(n-1-i))%MOD;	
	}

	ll ans = (n*termo)%MOD;

	cout << (ans - sub + MOD)%MOD << endl;
}
