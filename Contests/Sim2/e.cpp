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

#define MAXN 200010
#define MOD 998244353

int main(){
	int n;
	cin >> n;

	ll a[MAXN], b[MAXN];

	fr(i, n) cin >> a[i];
	fr(i, n) cin >> b[i];

	sort(a, a+n);
	sort(b, b+n);

	ll c[MAXN], d[MAXN];
	fr(i, n){
		c[i] = a[i]*b[n-1-i];
		d[i] = (i+1)*(n-i);
	}

	sort(c, c+n);
	sort(d, d+n);
	
	fr(i, n) c[i] = c[i]%MOD;
	fr(i, n) d[i] = d[i]%MOD;
 	
 	ll resp = 0;

 	fr(i, n){
 		//cout<< c[i] << " " << d[n-i-1] << endl;
 		resp += c[i]*d[n-i-1];
 		resp = resp%MOD;
 		
 		cout<< c[i] << "*" << d[n-i-1] << " + ";
 	}

 	cout << endl;

	cout << resp << endl;
}