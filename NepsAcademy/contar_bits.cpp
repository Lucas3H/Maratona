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

int count_bits(ll x){
	int resp = 0;
	while(x != 0){
		resp++;
		x -= (x&-x);
	}

	return resp;
}

int main(){
	ll x;
	cin >> x;

	cout << count_bits(x) << endl;

	return 0;
}