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

int n, k;
int price[MAXN];
int memo[MAXN][MAXN][MAXN];

int dp(int ind, int cap, int pack){
	if(ind == k+1 && cap > 0) return INF;
	if(ind == k+1 && cap == 0) return 0;

	if(memo[ind][cap][pack] != -1) return memo[ind][cap][pack];

	int pega1 = INF, pega2 = INF;

	if(cap >= ind && pack < n && price[ind] >= 0) {
		pega1 = price[ind] + dp(ind+1, cap - ind, pack+1);
		pega2 = price[ind] + dp(ind, cap - ind, pack+1);
	}
	
	int passa = dp(ind+1, cap, pack);

	return memo[ind][cap][pack] = min(pega1, min(passa, pega2));
}

int main(){
	int testCases;
	cin >> testCases;

	while(testCases--){
		cin >> n >> k;
		frr(i, k) cin >> price[i];

		mem(memo, -1);

		int d = dp(1, k, 0);
		if(d >= INF) cout << -1 << endl;
		else cout << d << endl;
	}
}