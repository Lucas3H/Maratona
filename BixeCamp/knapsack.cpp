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

#define MAXN 2010
#define INF 4000000

int n, k;
int memo[MAXN][MAXN];
int value[MAXN], wght[MAXN];

int dp(int ind, int cap){
	if(ind == n) return 0;
	if(cap == 0) return 0;
	
	if(memo[ind][cap] != -1) return memo[ind][cap];

	int pega = -1;
	if(cap >= wght[ind]) pega = value[ind] + dp(ind+1, cap - wght[ind]);
	int passa = dp(ind+1, cap);

	return memo[ind][cap] = max(pega, passa);
}


int main(){
	cin >> k >> n;

	mem(memo, -1);

	fr(i, n) cin >> wght[i] >> value[i];

	cout << dp(0, k) << endl;
}