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

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

int n, m;
int d[60][60];
string s;
int ri, ci, rf, cf;

char g[60][60];

int ans = MOD;

bool is_valid(int r, int c){
	if(r >= 1 && r <= n && c >= 1 && c <= m && g[r][c] != '#') return true;
	else return false;
}

void bfs(vector<pair<int, pii>> p){
	int pr[60][60];
	int da[60][60];
	frr(i, n){
		frr(j, m){
			pr[i][j] = 0;
			da[i][j] = MOD;
		}
	}

	queue<pii> fila;
	for(auto x: p) {
		fila.push(x.s);
		d[x.s.f][x.s.s] = x.f;
		pr[x.s.f][x.s.s] = 1;
	}

	for(auto x: p) {
		d[x.s.f][x.s.s] = min(x.f, d[x.s.f][x.s.s]);
		da[x.s.f][x.s.s] = d[x.s.f][x.s.s];
	}

	while(!fila.empty()){
		pii davez = fila.front();
		fila.pop();

		//db;

		fr(i, 4){
			if(is_valid(davez.f + x[i], davez.s + y[i])/* && pr[davez.f + x[i]][davez.s + y[i]] == 0*/){
				if(da[davez.f + x[i]][davez.s + y[i]] > da[davez.f][davez.s] + 1){
					da[davez.f + x[i]][davez.s + y[i]] = da[davez.f][davez.s] + 1;
					fila.push(mp(davez.f + x[i], davez.s + y[i]));
					pr[davez.f + x[i]][davez.s + y[i]] = 1;
				}
			}
		}
	}

	frr(i, n){
		frr(j, m) d[i][j] = da[i][j];
	}
}

void solve(int pos){
	vector<pair<int, pii>> podem;

	int mr, mc;

	if(s[pos] == 'L'){
		mr = 0;
		mc = -1;
	}
	else if(s[pos] == 'R'){
		mr = 0;
		mc = 1;
	}
	else if(s[pos] == 'D'){
		mr = 1;
		mc = 0;
	}
	else if(s[pos] == 'U'){
		mr = -1;
		mc = 0;
	}

	frr(i, n){
		frr(j, m){
			if(g[i][j] != '#'){
				if(is_valid(i + mr, j + mc)){
					podem.pb(mp(d[i][j], mp(i + mr, j + mc)));
				}
				else{
					podem.pb(mp(d[i][j], mp(i, j)));
				}
			}
		}
	}

	bfs(podem);
}

void read(){
	cin >> n >> m;

	frr(i, n){
		frr(j, m){
			d[i][j] = MOD;
		}
	}

	frr(i, n){
		frr(j, m) {
			cin >> g[i][j];

			if(g[i][j] == 'R'){
				ri = i;
				ci = j;
			}
			if(g[i][j] == 'E'){
				rf = i;
				cf = j;
			}
		}
	}

	cin >> s;
	vector<pair<int, pii>> aux;
	aux.pb(mp(0, mp(ri, ci)));

	bfs(aux);
	ans = d[rf][cf];
}

int main(){
	ios::sync_with_stdio(false);

	read();
/*
	frr(i, n){
		frr(j, m) cout << d[i][j] << " ";
		cout << endl;
	}

	cout << "--------------------------------\n";
*/
	fr(i, s.size()){
		solve(i);
		
	/*	
		cout << s[i] << endl;
		frr(i, n){
			frr(j, m) cout << d[i][j] << " ";
			cout << endl;
		}
		
	*/	
		ans = min(ans, d[rf][cf]);

		//cout << "--------------------------------\n";
	}
	/*
	frr(i, n){
		frr(j, m) cout << d[i][j] << " ";
		cout << endl;
	}
	*/
	cout << ans << endl;
}
