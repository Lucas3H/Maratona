#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

string s, p;

int dp[401][401];

int nxt[401][30];

int a[401], b[401];

int build(int lim){
	frr(i, lim){
		a[i] = p[i - 1] - 'a';
//		cout << a[i];
	}

//	cout << " ";

	frr(i, p.size() - lim){
		b[i] = p[i + lim - 1] - 'a';
//		cout << b[i];
	}
	dp[0][0] = 0;

	fr(i, lim + 1){
		fr(j, p.size() - lim + 1) dp[i][j] = -1;
	}

	dp[0][0] = 0;

	frr(i, lim){
		if(dp[i-1][0] > -1) dp[i][0] = nxt[dp[i-1][0]][a[i]];
	}

	frr(j, p.size() - lim){
		if(dp[0][j-1] > -1)dp[0][j] = nxt[dp[0][j-1]][b[j]];
	}

	frr(i, lim){
		frr(j, p.size() - lim){
			if(dp[i-1][j] == -1 && dp[i][j-1] == -1) continue;
			else if(dp[i - 1][j] == -1) dp[i][j] = nxt[dp[i][j - 1]][b[j]];
			else if(dp[i][j - 1] == -1) dp[i][j] = nxt[dp[i-1][j]][a[i]];
			else {
				if(nxt[dp[i-1][j]][a[i]] > -1 && nxt[dp[i][j - 1]][b[j]] > -1){
					dp[i][j] = min(nxt[dp[i-1][j]][a[i]], nxt[dp[i][j - 1]][b[j]]);
				}
				else if(nxt[dp[i-1][j]][a[i]] > -1){
					dp[i][j] = nxt[dp[i-1][j]][a[i]];		
				}
				else dp[i][j] = nxt[dp[i][j - 1]][b[j]];
			}
		}
	}
/*
	fr(i, lim + 1){
		fr(j, p.size() - lim + 1) printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
	}

	cout << endl << endl;
*/
	if(dp[lim][p.size() - lim] > 0) return 1;
	else return 0;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		mem(nxt, -1);

		cin >> s >> p;

		for(int i = s.size() - 1; i >= 0; i--){
			fr(j, 26){
				nxt[i][j] = nxt[i + 1][j];
			}

			nxt[i][s[i] - 'a'] = i + 1;
		}

		int deu = 0;
/*
		fr(i, s.size()){
			fr(j, 26) cout << nxt[i][j] << " ";
			cout << endl;
		}
*/
		for(int i = 0; i < p.size(); i++){
			if(build(i + 1)) deu = 1;
		}

		if(deu) cout << "YES\n";
		else cout << "NO\n";
	}
}
