// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=158&page=show_problem&problem=925
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

#define MAXN 250010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n;
string s;
pii pos[MAXN];

map<int, vector<int>> x, y;
set<int> xs, ys;

bool comp1(int a, int b){
	return pos[a].f < pos[b].f;
}

bool comp2(int a, int b){
	return pos[a].s < pos[b].s;
}

void build(){
	cin >> n;
	cin >> s;

	x.clear();
	y.clear();
	xs.clear();
	ys.clear();

	int a = 0, b = 0;
	pos[0] = mp(0, 0);
	x[0].pb(0);
	y[0].pb(0);

	xs.insert(0);
	ys.insert(0);

	frr(i, n){
		if(s[i-1] == 'N') b++;
		else if(s[i-1] == 'S') b--;
		else if(s[i-1] == 'E') a++;
		else a--;

		pos[i] = mp(a, b);
	
		xs.insert(a);
		ys.insert(b);

		x[a].pb(i);
		y[b].pb(i);
	}

	for(auto a: xs){
		sort(x[a].begin(), x[a].end(), comp2);
	}

	for(auto a: ys){
		sort(y[a].begin(), y[a].end(), comp1);
	}
}

void solve(){
	vector<pair<pii, char>> ans;
	
	int l = MAXN;
	for(auto a: x){
		vector<int> v = a.s;

		fr(i, v.size() - 1){
			if(abs(v[i] - v[i+1]) <= 1) continue;

			if(l >= pos[v[i + 1]].s - pos[v[i]].s){

				if(pos[v[i + 1]].s - pos[v[i]].s < l) ans.clear();

				l = pos[v[i + 1]].s - pos[v[i]].s;

				if(v[i+1] > v[i]) ans.pb(mp(mp(v[i], -v[i+1]), 'N'));
				else ans.pb(mp(mp(v[i + 1], -v[i]), 'S')); 
			}
		}
	}


	for(auto a: y){
		vector<int> v = a.s;

		fr(i, v.size() - 1){
			if(abs(v[i] - v[i+1]) <= 1) continue;

			if(l >= pos[v[i + 1]].f - pos[v[i]].f){

				if(pos[v[i + 1]].f - pos[v[i]].f < l) ans.clear();

				l = pos[v[i + 1]].f - pos[v[i]].f;

				if(v[i+1] > v[i]) ans.pb(mp(mp(v[i], -v[i+1]), 'E'));
				else ans.pb(mp(mp(v[i + 1], -v[i]), 'W')); 
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << l << ' ' << ans[0].f.f << ' ' << -ans[0].f.s <<  " " << ans[0].s << endl;
}

int main(){
	ios::sync_with_stdio(false);

	int ts;
	cin >> ts;

	while(ts--){
		build();
		solve();

		if(ts) cout << endl;
	}
}
