#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define ll long long

#define MAXN 5002

int a[MAXN];
int memo[MAXN][MAXN];

int dp(int pos, int teams){
      if(teams == 0 || pos == -1) return 0;

      if(memo[pos][teams] > -1) return memo[pos][teams];

      int j = pos;
      while(a[j] >= a[pos] - 5 && j >= 0) j--;

      int x = dp(j, teams - 1) + pos - j;
      int y = dp(pos-1, teams);

      //cout << max(x, y) << " " << pos << " " << teams << endl;

      return memo[pos][teams] = max(x, y);
}

int main(){
	   ios::sync_with_stdio(false);

     int n, k;
     cin >> n >> k;

     fr(i, n) cin >> a[i];

     mem(memo, -1);

     sort(a, a+n);

     cout << dp(n-1, k) << endl;
}
