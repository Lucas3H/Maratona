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
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int a[100][100], b[100][100];
vector<pii> ans;
void transform(int x, int y){
	b[x][y] = 1;
	b[x+1][y] = 1;
	b[x+1][y+1] = 1;
	b[x][y+1] = 1;
	ans.pb(mp(x, y));
}

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	frr(i, n){
		frr(j, m) cin >> a[i][j];
	}

	frr(i, n-1){
		frr(j, m-1){
			if(a[i][j] == 1 && b[i][j] == 0) transform(i, j);
		}

		if(a[i][m] == 1 && a[i][m-1] == 1) transform(i, m-1);
		if(a[i][m] == 1 && a[i][m-1] == 0){
			cout << -1 << endl;
			return 0;
		}
	}

	frr(i, m-1){
		if(a[n-1][i] == 1 && a[n][i] == 1) transform(m-1, i);
		if(a[n-1][i] == 0 && a[n][i] == 1){
			cout << -1 << endl;
			return 0;
		}
	}


	if(a[n][m-1] == 1 && a[n-1][m] == 1 && a[m][n] == 1) transform(m-1, n-1);

	frr(i, n){
		frr(j, m){
			if(a[i][j] != b[i][j]){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << ans.size() << endl;
	fr(i, ans.size()){
		cout << ans[i].f << " " << ans[i].s << endl;
	}
}
