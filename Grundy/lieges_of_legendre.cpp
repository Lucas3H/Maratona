// https://codeforces.com/problemset/problem/603/C
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
#define MOD 1000000007

ll n, k;
ll mex(ll t){
	if(t == 0) return 0;

	if(k%2 == 0){
		if(t == 1) return 1;
		if(t == 2) return 2;
		if(t%2 == 1) return 0;
		else return 1;		
	}
	else{
		if(t == 1) return 1;
		if(t == 2) return 0;
		if(t == 3) return 1;
		if(t == 4) return 2;

		if(t%2 == 1) return 0;

		ll m = mex(t/2);

		if(m == 0 || m == 2) return 1;
		else return 2;
	}
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> k;

	ll a, sum = 0;
	frr(i, n){
		cin >> a;
		sum^=mex(a);
	}

	if(sum != 0) cout << "Kevin\n";
	else cout << "Nicky\n";

}
