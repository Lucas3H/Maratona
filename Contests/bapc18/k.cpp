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
#define INF 987654321

int n, h;
vector<int> adj[MAXN];
int folha = -1;
int best = -1;
int pr[MAXN];
int folhas[MAXN];
int folhas_tot = 0;
int pai[MAXN];

vector<int> folhas_des[MAXN];

void read(){
	cin >> n >> h;
	h++;
	fr(i, n-1){
		int a, b;
		cin >> a >> b;
		a++;
		b++;
		adj[a].pb(b);
		adj[b].pb(a); 
	}

	frr(i, n){
		if(adj[i].size() == 1) folha = i;
	}
}

void find_folhas(int v){
	pr[v] = 1;
	for(auto x: adj[v]){
		if(!pr[x]){
			pai[x] = v;
			find_folhas(x);
			folhas[v] += folhas[x];
		}
	}

	if(adj[v].size() == 1) {
		folhas_tot++;
		folhas[v]++;
	}
}

void find_best(int v){
	vector<pii> filhos;
	int sum = 0;

	for(auto x: adj[v]){
		if(x != pai[v]){
			sum+=folhas[x];
			filhos.pb({folhas[x], x});
		}
	}

	filhos.pb({folhas_tot - sum, pai[v]});
	sort(filhos.begin(), filhos.end());

	if(2*filhos.back().f <= folhas_tot){
		best = v;
		return;
	}
	else
		find_best(filhos.back().s);
}

void mark_folhas(int v, int ind){
	pr[v] = 1;
	for(auto x: adj[v]){
		if(!pr[x] && x != best){
			mark_folhas(x, ind);
		}
	}

	if(adj[v].size() == 1)
		folhas_des[ind].pb(v);
}

void solve(){
	pq<pii> fila;
	pii aux[2];
	for(auto x: adj[best]){
		fila.push({folhas_des[x].size(), x});
	}

	cout<< (folhas_tot+1)/2 << endl;

	while(fila.size() > 1){
		pii a = fila.top();
		fila.pop();
		pii b = fila.top();
		fila.pop();

		aux[0] = {folhas_des[a.s].back(), a.s};
		aux[1] = {folhas_des[b.s].back(), b.s};

		cout << folhas_des[a.s].back() - 1 << " " << folhas_des[b.s].back() - 1 << endl;
		folhas_des[a.s].pop_back();
		folhas_des[b.s].pop_back();

		if(folhas_des[a.s].size())
			fila.push({folhas_des[a.s].size(), a.s});
		if(folhas_des[b.s].size())
			fila.push({folhas_des[b.s].size(), b.s});
	}

	if(fila.size() == 1){
		pii a = fila.top();
		fila.pop();

		if(a.s != aux[0].s){
			cout << folhas_des[a.s].back() - 1 << " " << aux[0].f - 1 << endl;
		}
		else{
			cout << folhas_des[a.s].back() - 1<< " " << aux[1].f - 1 << endl;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	read();

	if(n == 2){
		cout << 1 << endl;
		cout << 0 << " " << 1 << endl;
		return 0;
	}

	find_folhas(h);
/*
	frr(i, n){
		cout << folhas[i] << endl;
	}
*/
	mem(pr, 0);

	find_best(folha);

	for(auto x: adj[best]){
		mark_folhas(x, x);
		/*
		cout << x << " carai" << endl;
		for(auto y: folhas_des[x]){
			cout << y << " ";
		}
		cout << endl;
		*/
	}

	solve();
}
