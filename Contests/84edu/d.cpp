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

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n, n_cycles;
int p[MAXN], used[MAXN];
int c[MAXN];
vector<vector<int>> cycles;

void build(int ini, int ind){
	int davez = p[ini];

	vector<int> cy;

	cy.pb(ini);
	while(davez != ini){
		cy.pb(davez);
		davez = p[davez];
		used[davez] = 1;
	}

	used[ini] = 1;

	cycles.pb(cy);
}

vector<int> cyc;

int find_min(){
	int tam = cyc.size();
	
	int i, r, q;

	for(i = 1; i <= tam; i++){
		if(tam%i == 0){
			int l = tam/i;

			int deu_ruim = 0;

			for(r = 0; r < i; r++){

				deu_ruim = 0;

				for(q = 1; q < l; q++){
					if(c[cyc[i*q + r]] != c[cyc[i*(q-1) + r]]){
						deu_ruim = 1;
						break;
					}
				}

				if(deu_ruim == 0){
					return i;
				}
			}
		}
	}

	return 0;
}

void read(){
	cin >> n;

	cycles.clear();
	n_cycles = 0;
	frr(i, n) used[i] = 0;
	
	frr(i, n) cin >> p[i];
	frr(i, n) cin >> c[i];

	frr(i, n){
		if(used[i] == 0){
			build(i, n_cycles);
			n_cycles++;
		}
	}
}

void solve(){
	int ans = n;

	fr(i, n_cycles){
		cyc = cycles[i];
		ans = min(ans, find_min());
	}

	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		read();
		solve();
	}
}
