//  https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1242
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<double,double> pii;
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

int n;
vector<int> adj[110];
int pr[110];

pii pt[MAXN];
double r[MAXN];

double dist(pii a, pii b){
	return (a.f - b.f)*(a.f - b.f) + (a.s - b.s)*(a.s - b.s);
}

int read(){
	cin >> n;
	if(n == -1) return 0;

	fr(i, n){
		pr[i] = 0;
		adj[i].clear();
	}

	fr(i, n){
		cin >> pt[i].f >> pt[i].s >> r[i];
	}

	return 1;
}

int dfs(int v){
	pr[v] = 1;

	int ret = 1;
	for(auto x: adj[v]){
		if(!pr[x]){
			ret+=dfs(x);
		}
	}

	return ret;
}

void solve(){
	fr(i, n){
		fr(j, i){
			double d = dist(pt[i], pt[j]);

			if(d > (r[i] - r[j])*(r[i] - r[j]) && d < (r[i] + r[j])*(r[i] + r[j])){
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}

	int ans = 0;
	fr(i, n){
		if(!pr[i]){
			ans = max(ans, dfs(i));
		}
	}

	if(ans != 1) printf("The largest component contains %d rings.\n", ans);
	else  printf("The largest component contains %d ring.\n", ans);
}

int main(){
	ios::sync_with_stdio(false);

	while(read()){
		solve();
	}
}
