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

#define MAXN 110
#define INF 1000000

int n, k
int price[MAXN];
inf memo[MAXN][MAXN][MAXN];

int dp(int ind, int cap, int pack){
	if(ind == n) return 0;

	if(memo[ind][cap][pack] != -1) return memo[ind][cap][pack];

	int pega = INF;
	if(cap >= ind && pack < n) pega = price[ind] + dp(ind+1, cap - ind, pack+1);
	int passa = dp(ind+1, cap, pack);

	return memo[ind][cap][pack] = min(pega, passa);
}

int main(){
	int testCases;
	cin >> testCases;
	while(testCases--){
		cin >> n >> k;
		frr(i, k) cin << price[i];

		mem(memo, -1);

		cout << dp(1, k, 0) << endl;
	}
}