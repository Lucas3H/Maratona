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

#define MAXN 4010

int memo[MAXN];

int n, a, b, c;

int dp(int len){
	if(len < 0) return -MAXN;
	if(len == 0) return 0;
	if(memo[len] != -1) return memo[len];

	int x = dp(len - a);
	int y = dp(len - b);
	int z = dp(len - c);

	return memo[len] = max(x, max(y, z)) + 1;
}

int main(){
	cin >> n >> a >> b >> c;

	mem(memo, -1);

	int d = dp(n);

	if(d < 0) cout << 0 << endl;
	else cout << d << endl;
}