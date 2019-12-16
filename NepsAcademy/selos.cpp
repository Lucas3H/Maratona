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

bool da_certo(ll x){
	for(int i = 2; i <= sqrt(x); i ++){
		if(x%i == 0) return 1;
	}

	return 0;
}

int main(){
	ll n;
	cin >> n;

	if(da_certo(n)) cout << "S" << endl;
	else cout << "N" << endl;

	return 0;
}
