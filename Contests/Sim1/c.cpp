#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
//#define v.erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 100010

ll n, m, g, x;

int achou = 0, ind;

int main(){
	cin >> n >> m;

	ll resp = 0, B = 0, G = 0;
	vector<ll> b;
	fr(i, n){
		cin >> x;
		B += x;
		b.pb(x);
	}

	sort(b.begin(), b.end());

	ind = n-1;

	fr(i, m){
		cin >> g;

		if(g < b[n-1] || ind < 0){
			cout << -1 << endl;
			return 0;
		}
		else if(g == b[n-1]) achou = 1;

		G += g; 

		if(!achou && i == m-2) ind--;
	}

	resp += B*m;
	resp += G;
	resp -= m*b[n-1];
	
	if(!achou) resp += b[n-1] - b[n-2];

	cout << resp << endl;

	return 0;
}