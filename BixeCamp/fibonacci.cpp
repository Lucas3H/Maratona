#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 100

ll f[MAXN];

ll fib(ll x){
	if(f[x] != -1) return f[x];

	return f[x] = fib(x-1) + fib(x-2);
}

int main(){
	ll n;
	cin >> n;

	mem(f, -1);
	f[0] = 0;
	f[1] = 1;

	fr(i, n){
		ll t;
		cin >> t;
		cout << "Fib("<< t << ") = " << fib(t) << endl;

	}
}