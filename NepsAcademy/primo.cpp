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

bool eh_primo(ll x){
	if(x == 1) return 0;

	for(int i = 2; i*i <= x; i ++){
		if(x%i == 0) return 0;
	}

	return 1;
}

int main(){
	ll n;
	cin >> n;

	if(eh_primo(n)) cout << "S" << endl;
	else cout << "N" << endl;

	return 0;
}
