#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll, ll> pll;
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
#define INF 1000000000000000100

ll mr[8] = {2, 2, 1, 1, -1, -1, -2, -2};
ll mc[8] = {-1, 1, 2, -2, 2, -2, -1, 1};

ll dp[501][8][7][5][3];
ll r, c;
char m[501][501];
ll cavalo[501];

bool is_inside(ll x, ll y){
	return (x >= 0 && x < r && y >= 0 && y < c && m[x][y] == '.');
}

bool is_valid(ll ind, ll mov, ll a, ll b, ll c, ll d){
	pii aux = mp(ind + mr[mov], cavalo[ind] + mc[mov]);
	if(m[ind + mr[mov]][cavalo[ind] + mc[mov]] == '#' || m[ind + mr[mov]][cavalo[ind] + mc[mov]] == '*') 
    return false;
	if(ind > 0 && aux == mp(ind-1 + mr[a], cavalo[ind-1] + mc[a])) 
		return false;
	if(ind > 1 && b < 7 && aux == mp(ind-2 + mr[b], cavalo[ind-2] + mc[b])) 
		return false;
	if(ind > 2 && c < 4 && aux == mp(ind-3 + mr[c], cavalo[ind-3] + mc[c])) 
		return false;
	if(ind > 3 && d < 2 &&  aux == mp(ind-4 + mr[d], cavalo[ind-4] + mc[d])) 
		return false;
	return true;
}	

/*
pd[r][mov][a][b][c][d]
-> o número de maneiras de colocar os (r + 1) primeiros cavalos de forma que o r fez o movimento mov,
o r-1 fez o movimento a , etc.
*/

void solve(){
	fr(mov, 8) {
		if(!is_inside(0 + mr[mov], cavalo[0] + mc[mov])) continue;
		dp[0][mov][0][0][0] = 1;
	}
  
	if(r < 2) return;

	fr(mov, 8){
		if(!is_inside(1 + mr[mov], cavalo[1] + mc[mov])) continue;
			
		fr(a, 8){
			if(!is_inside(0 + mr[a], cavalo[0] + mc[a])) continue;

			if(is_valid(1, mov, a, 0, 0, 0)){
				int A = a;
				if(a > 6) A = a;	
				dp[1][mov][A][0][0] = (dp[0][a][0][0][0] + dp[1][mov][A][0][0])%MOD;
			}
		}	
	}

	//cout << ans[1] << endl;

	if(r < 3) return;

	fr(mov, 8){
		if(!is_inside(2 + mr[mov], cavalo[2] + mc[mov])) continue;
		fr(a, 8){
			if(!is_inside(1 + mr[a], cavalo[1] + mc[a])) continue;
			fr(b, 7){
				if(b < 6 && !is_inside(0 + mr[b], cavalo[0] + mc[b])) continue;
			
				if(is_valid(2, mov, a, b, 0, 0)){	
					int B = b, A = a;
					if(b > 4) B = 4;
					if(a > 6) A = 6;
					dp[2][mov][A][B][0] = (dp[1][a][b][0][0] + dp[2][mov][A][B][0])%MOD;	
				}
			}
		}		
	}

	if(r < 4) return;


	fr(mov, 8){
		if(!is_inside(3 + mr[mov], cavalo[3] + mc[mov])) continue;
		fr(a, 8){
			if(!is_inside(3 - 1 + mr[a], cavalo[3 - 1] + mc[a])) continue;
			fr(b, 7){
				if(b < 6 && !is_inside(1 + mr[b], cavalo[1] + mc[b])) continue;
			
				fr(c, 5){
					if(c < 4 && !is_inside(0 + mr[c], cavalo[0] + mc[c])) continue;
					
					if(is_valid(3, mov, a, b, c, 0)){	
						int C = c, B = b, A = a;
						if(c > 2) C = 2;
						if(b > 4) B = 4;
						if(a > 6) A = 6;
						dp[3][mov][A][B][C] = (dp[2][a][b][c][0] + dp[3][mov][A][B][C])%MOD;
					}
				}
			}
		}
	}

	if(r < 5) return;

	for(int linha = 4; linha < r; linha++){
		fr(mov, 8){
			pii aux = mp(linha + mr[mov], cavalo[linha] + mc[mov]);
			if(!is_inside(linha + mr[mov], cavalo[linha] + mc[mov])) continue;
			if(m[linha + mr[mov]][cavalo[linha] + mc[mov]] == '#' || m[linha + mr[mov]][cavalo[linha] + mc[mov]] == '*') continue;
    
			fr(a, 8){
				if(!is_inside(linha - 1 + mr[a], cavalo[linha-1] + mc[a])) continue;
				if(aux == mp(linha-1 + mr[a], cavalo[linha-1] + mc[a])) continue;

				fr(b, 7){
					if(b < 6 && !is_inside(linha-2 + mr[b], cavalo[linha-2] + mc[b])) continue;
					if(aux == mp(linha-2 + mr[b], cavalo[linha-2] + mc[b])) continue;

					fr(c, 5){
						if(c < 4 && !is_inside(linha-3 + mr[c], cavalo[linha-3] + mc[c])) continue;
						if(aux == mp(linha-3 + mr[c], cavalo[linha-3] + mc[c])) continue;

						fr(d, 3){
							if(d < 2 && !is_inside(linha-4 + mr[d], cavalo[linha-4] + mc[d])) continue;
							if(aux == mp(linha-4 + mr[d], cavalo[linha-4] + mc[d])) continue;

							int C = c, B = b, A = a;	
							if(c > 2) C = 2;
							if(b > 4) B = 4;
							if(a > 6) A = 6;
               				dp[linha][mov][A][B][C] = (dp[linha-1][a][b][c][d] + dp[linha][mov][A][B][C])%MOD;
						}	
					}
				}
			}
		}
	}
}

void read(){
	cin >> r >> c;
	fr(i, r){
		fr(j, c) {
			cin >> m[i][j];
			if(m[i][j] == '*') cavalo[i] = j;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("knights.in", "r", stdin);
	
	ll t;
	cin >> t;

	while(t--
		//db;
		read();
		solve();
		
		ll ans = 0;
		fr(mov, 8){
			fr(a, 7){
				fr(b, 5){
					fr(c, 3){
						ans = (ans + dp[r-1][mov][a][b][c])%MOD;
					}
				}
			}
		}

		cout << ans << endl;
		mem(dp, 0);
	}
}
