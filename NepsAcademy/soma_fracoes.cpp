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

#define MAXN 100010

int mdc(ll a, ll b){
	if(b == 0) return a;
	return mdc(b, a%b);
}

int main(){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll den = b*d;
	ll num = a*d + b*c;

	ll m = mdc(num, den);
	num /= m;
	den /= m;

	cout << num << " " << den << endl;

	return 0;
}
