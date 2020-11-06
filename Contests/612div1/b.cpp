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

int n;
int deu = 1;
int a[MAXN], c[MAXN];

vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], t = 1, pr[MAXN];

void dfs(int v){
	pr[v] = 1;
	tin[v] = t++;

	for(auto x: adj[v]){
		if(!pr[x]) dfs(x);
	}

	tout[v] = t-1;
}

void build(int l, int r, int v){
	if(l == r){
		if(c[v] > 0){
			deu = 0;
			a[l] = 1;
		}
		else{
			a[l] = 1;
		}

		return;
	}

	for(auto x: adj[v]){
		//cout << "V " << v<< ' ' << x<< endl;
		build(tin[x], tout[x], x);
	}
/*
	frr(i, n) cout << a[i]<< " ";
	cout << 'o' << endl;
*/
	vector<pii> aux;
	for(int i = l + 1; i <= r; i++){
		aux.pb(mp(a[i], i));
	}

	sort(aux.begin(), aux.end());

	int cut = 0;

	if(c[v] > (r - l)){
		deu = 0;
		a[l] = 1;
	}
	else{
		cut = aux[c[v] - 1].f;
		//cout << cut << " " << endl;

		int acima = r - l - c[v];
		for(int i = c[v]; i < aux.size(); i++){
			a[aux[i].s]++;
		}

		if(c[v] > 0) a[l] = aux[c[v] - 1].f + 1;
		else a[l] = 1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	mem(pr, 0);
	cin >> n;

	int x, y, root;
	frr(i, n){
		cin >> x >> y;
		adj[x].pb(i);
		c[i] = y;

		if(x == 0) root = i;
	}

	dfs(root);

	build(tin[root], tout[root], root);

	if(deu){
		cout << "YES" << endl;
		frr(i, n) cout << a[tin[i]] << " ";
	}
	else{
		cout << "NO" << endl;
	}
}
