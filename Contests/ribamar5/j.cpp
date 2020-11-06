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

#define MAXN 300010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

struct peca{
	int n, w, e, s;
};

int n, h, w, zero;
peca p[MAXN];
int corner = -1;
bool used[MAXN];

vector<int> m[2000000];

void rotaciona(int ind){
	int aux = p[ind].n;
	p[ind].n = p[ind].w;
	p[ind].w = p[ind].s;
	p[ind].s = p[ind].e;
	p[ind].e = aux;
}

int getSibling(int ind, int P){
	if(m[P][0] == ind) {
		if(used[m[P][1]]) abort();
		return m[P][1];
	}
	else {
		if(used[m[P][0]]) abort();
		return m[P][0];
	}
}

void read(){
	cin >> n;

	frr(i, n){
		cin >> p[i].n >> p[i].w >> p[i].s >> p[i].e;

		m[p[i].n].pb(i);
		m[p[i].w].pb(i);
		m[p[i].s].pb(i);
		m[p[i].e].pb(i);

		int deu = 0;

		if(p[i].n == 0){
			if(p[i].w == 0) deu = 1;
			zero++;
		}
		if(p[i].w == 0){
			if(p[i].s == 0) deu = 1;
			zero++;
		}
		if(p[i].s == 0){
			if(p[i].e == 0) deu = 1;
			zero++;
		}

		if(p[i].e == 0){
			if(p[i].n == 0) deu = 1;
			zero++;
		}

		if(deu) corner = i;
	}
}

void abort(){
	cout << "impossible\n";
	exit (0);
}

vector<int> ans[MAXN];

int solvePrimeira(){
	int W = 1;
	int atual = corner;
	
	while(p[corner].w != 0 || p[corner].n != 0){
		rotaciona(corner);
	}

	while(W <= n){
		used[atual] = true;
		ans[0].pb(atual);

		if(p[atual].e == 0){
			return W;
		}

		int prox = getSibling(atual, p[atual].e);

		while(p[prox].w != p[atual].e){
			rotaciona(prox);
		}

		if(p[atual].n != 0) abort();

		atual = prox;
		W++;
	}

	return W;
}

void solve(int linha){
	for(int i = 0; i < w; i++){
		int atual = getSibling(ans[linha-1][i], p[ans[linha-1][i]].s);

		if(p[ans[linha-1][i]].s == 0) abort();

		while(p[atual].n != p[ans[linha-1][i]].s){
			rotaciona(atual);
		}

		used[atual] = true;
		ans[linha].pb(atual);
	}

	if(p[ans[linha][0]].w != 0) abort();
	if(p[ans[linha][w-1]].e != 0) abort();

	for(int i = 1; i < w; i++){
		if(p[ans[linha][i-1]].e == 0) abort();
		if(p[ans[linha][i-1]].e != p[ans[linha][i]].w) abort();
	}
}

void checkLast(){
	for(int i = 0; i < w; i++){
		if(p[ans[h-1][i]].s != 0) abort();
	}
}

int main(){
	read();

	if(corner == -1){
		cout << "impossible\n";
		return 0;
	}

	w = solvePrimeira();

	if(n%w != 0){
		cout << "impossible\n";
		return 0;
	}

	h = n/w;

	for(int i = 1; i < h; i++){
		solve(i);
	}

	checkLast();

	printf("%d %d\n", h, w);
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}
