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

string s;
ll n, m, k;
ll adj[30][30];
ll best[30][30];
ll pr[30];

ll memo[MAXN][30];

ll ac[MAXN][30];

ll dp(ll pos, ll letra){
	if(memo[pos][letra] > -1){
		return memo[pos][letra];
	}

	if(pos == s.size() +1) return 0;

	ll menor = MOD;
	if(pos > 1) menor = dp(pos+1, letra) + best[s[pos-1] - 'a' + 1][letra];

	if(pos + k <= s.size() + 1){
		frr(i, m){
			menor = min(menor, ac[pos+k-1][i] - ac[pos-1][i] + dp(pos+k, i));
		}
	}

	

	return memo[pos][letra] = menor;
}

void bfs(ll v){
	pq<pii, vector<pii>, greater<pii>> fila;
	fila.push(mp(0, v));
	frr(i, m) pr[i] = 0;
	
	while(true){
		ll davez = -1;

		while(!fila.empty()){
			pii aux = fila.top();
			fila.pop();

			if(pr[aux.s] == 0){
				pr[aux.s] = 1;
				best[v][aux.s] = min(aux.f, best[v][aux.s]);
				davez = aux.s;
				break;
			}
		}

		if(davez == -1)
			break;

		for(ll i = 1; i <= m; i++){
			if(!pr[i]){
				fila.push(mp(adj[davez][i] + best[v][davez], i));
			}
		}
	}
}

void read(){
	cin >> n >> m >> k;
	cin >> s;

	fr(i, m){
		fr(j, m){
			best[i][j] = MOD;
		}
	}

	frr(i, m){
		frr(j, m){
			cin >> adj[i][j];
			best[i][j] = MOD;
		}
	}

	frr(i, m) bfs(i);
}

void build(){
	frr(i, m){
		frr(j, n){
			ac[j][i] = ac[j-1][i] + best[s[j-1] - 'a' + 1][i];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	read();
	mem(memo, -1);
	build();

	ll ans = MOD;
	frr(i, m){
		ans = min(ans, dp(1, i));
	}

	cout << ans << endl;
}
