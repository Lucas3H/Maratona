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

#define MAXN 101

int memo[MAXN];

int dp(int n){
	if(n == 1) return 1;

	if(memo[n]!=-1) return memo[n];

	return memo[n] = dp(n-1) + n*n;
}

int main(){
	int n;
	cin >> n;
	mem(memo, -1);

	while(n != 0){
		cout << dp(n) << endl;

		cin >> n;
	}

	return 0;
}