#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 200010
#define MOD 998244353

int main(){
	ll n;
	ll a[MAXN], b[MAXN];

	cin >> n;

	fr(i, n){
		cin >> a[i];
		a[i] = a[i]*(n-i)*(i+1);
}

	fr(i, n) cin >> b[i];

	sort(b, b+n);
	sort(a, a+n);

	ll resp = 0;

	fr(i, n){
		a[i] = a[i]%MOD;
		resp += a[i]*b[n-1-i];

		resp = resp%MOD;
	}

	cout << resp << endl;

}