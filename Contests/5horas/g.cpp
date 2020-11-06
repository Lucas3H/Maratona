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

int n;
set<int> adj[2600];


pii e[2600];

void read(){
	cin >> n;

	fr(i, n-1){
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].insert(v2);
		adj[v2].insert(v1);
		e[i] = mp(v1, v2);
	}
}

int dist[2600], pai[2600];
void dfsC(int v, int tipo){
	for(auto x: adj[v]){
		if(dist[x] == -1){
			if(tipo == 2) pai[x] = v;
			dist[x] = dist[v] + 1;
			dfsC(x, tipo);
		}
	}
}

pii findCentroid(int v){
	frr(i, n) dist[i] = -1;
	dist[v] = 0;
	dfsC(v, 1);

	int maximo = 0;
	frr(i, n){
		if(dist[maximo] < dist[i]) maximo = i;
	}

	frr(i, n) dist[i] = -1;
	dist[maximo] = 0;
	dfsC(maximo, 2);

	maximo = 0;
	int diam;

	frr(i, n){
		if(dist[maximo] < dist[i]) maximo = i;
	}

	diam = dist[maximo];

	fr(i, diam/2){
		maximo = pai[maximo];
	}

	if(diam == 0) maximo = v;

	return mp(diam, maximo);
}

int a[2], b[2], d = MAXN;
void solve(int i){
	int v = e[i].f;
	int x = e[i].s;

	adj[v].erase(x);
	adj[x].erase(v);

	pii a1 = findCentroid(v), a2 = findCentroid(x);
/*
	cout << v << " " << x << endl;
	cout << a1.f << " " << a1.s << endl;
	cout << a2.f << " " << a2.s << endl;

	cout << endl;
*/
	if(d > max((a1.f + 1)/2 + (a2.f + 1)/2 + 1, max(a1.f, a2.f))){
		d = max((a1.f + 1)/2 + (a2.f + 1)/2 + 1, max(a1.f, a2.f));
		a[0] = x;
		b[0] = v;
		a[1] = a1.s;
		b[1] = a2.s;
	}

	adj[v].insert(x);
	adj[x].insert(v);

}

int main(){
	ios::sync_with_stdio(false);
	read();

	fr(i, n-1) solve(i);

	cout << d << endl;
	cout << a[0] << " " << b[0] << endl << a[1] << " " << b[1] << endl;
}
