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
#define MOD 1000000007

int memo[MAXN][MAXN];
int n, k, d;
	
ll dp(int cap, int apareceu){
	if(cap == 0 && apareceu) return 1;
	if(cap == 0 && !apareceu) return 0;

	if(memo[cap][apareceu] != -1) return memo[cap][apareceu];

	ll resp = 0;
	for(int i = 1; i <= k && i <= cap; i++){
		if(i >= d) resp += dp(cap - i, 1);
		else resp+= dp(cap - i, apareceu);
	}

	return memo[cap][apareceu] = resp%MOD;
}

int main(){
	cin >> n >> k >> d;

	mem(memo, -1);

	ll d = dp(n, 0);

	cout << d << endl;
}