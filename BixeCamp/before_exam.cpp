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

#define MAXN 31
#define INF 1000000

int n, k;
int m[MAXN], M[MAXN];
int memo[MAXN][250][10];

int dp(int day, int st, int t){
	if(day == n+1 && st == 0) return 0;
	if(day == n+1 && st > 0) return -INF;
	if(t+m[day] > st || t + m[day] > M[day]) return -INF;

	if(memo[day][st][t] != -1) return memo[day][st][t];

	int cont = -INF, prox = -INF;

	cont = dp(day, st, t+1);
	prox = dp(day+1,st - t - m[day], 0);

	return memo[day][st][t] = max(cont, prox);
}

vector<int> ans;

void recover(int day, int st, int t){
	if(day == n+1 && st == 0) return;
	if(day == n+1 && st > 0) return;
	if(t+m[day] > st || t + m[day] > M[day]) return;

	int cont = -INF, prox = -INF;

	cont = dp(day, st, t+1);
	prox = dp(day+1,st - t - m[day], 0);

	if(cont < 0 && prox < 0) return;
	else if(prox == 0){
		ans.pb(t+m[day]);
		recover(day+1, st - t - m[day], 0);
	}
	else if(cont == 0){
		recover(day, st, t+1);
	}
}	


int main(){
	cin >> n >> k;

	frr(i, n) cin >> m[i] >> M[i];

	mem(memo, -1);

	int d = dp(1, k, 0);

	if(d < 0) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		recover(1, k, 0);
		fr(i, ans.size()) cout << ans[i] << " ";
		cout << endl;
	}
}