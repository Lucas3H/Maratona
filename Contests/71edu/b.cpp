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

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

int m[61][61];
int b[61][61];
vector<pii> ans;
void op(int x, int y){
	ans.pb(mp(x, y));
	b[x][y] = 1;
	b[x+1][y] = 1;
	b[x][y+1] = 1;
	b[x+1][y+1] = 1;
}

int main(){
	ios::sync_with_stdio(false);
	int c, r;
	cin >> r >> c;

	frr(i, r){
		frr(j, c) cin >> m[i][j];
	}

	int deu = 0;
	frr(i, r-1){
		frr(j, c-1){
			if(m[i][j] == 1 && m[i + 1][j] == 1 && m[i][j+1] == 1 && m[i+1][j+1] == 1){
				op(i, j);
			}
		}
	}

	frr(i, r){
		frr(j, c) if(m[i][j] != b[i][j]) deu = 1;
	}

	if(deu) cout << -1 << endl;
	else{
		cout << ans.size() << endl;
		fr(i, ans.size()) cout << ans[i].f << " " << ans[i].s << endl;
	}
}
