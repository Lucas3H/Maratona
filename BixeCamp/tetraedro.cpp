#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define MAXN 10000001
#define MOD 1000000007

int main(){
	int n;
	cin >> n;

	ll d1 = 0, d2 = 3, d3 = 3;
	for(int i = 1; i <= n-2; i++) {
		d3 = 3*d1 + 2*d2;
		d3 = d3%MOD;
		d1 = d2;
		d2 = d3;
	}

	if(n>=2) cout << d3 << endl;
	else cout << 0 << endl;
}