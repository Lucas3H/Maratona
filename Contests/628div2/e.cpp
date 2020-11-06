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
#define MAXP 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int is_prime[MAXP];
int indice[MAXP];
vector<int> p;

void crivo(){
	for(int i = 2; i < MAXP; i++){
		if(is_prime[i] == 0){
			indice[i] = p.size();
			p.pb(i);
			for(int j = 2; j*i < MAXP; j++){
				is_prime[j*i] = 1;
			}
		}
	}
}

int quadrado, deu;
int sozinho[MAXN];
set<int> adj[MAXN];

vector<pii> edges;

void build(int x){
	int i = 0;
	vector<int> s;

	while(p[i] < 1000 && p[i]*p[i] <= x){
		if(x%p[i] == 0){
			int multi = 0;
			while(x%p[i] == 0){
				multi++;
				x/=p[i];
			}

			if(multi%2 == 1){
				s.pb(i);
			}
		}
		i++;
	}

	if(x > 1){
		s.pb(indice[x]);
	}

	if(s.size() == 0){
		quadrado = 1;
	}
	else if(s.size() == 1){
		sozinho[s[0]]++;
		if(sozinho[s[0]] > 1) deu = 1;
	}
	else{
		edges.pb(mp(s[0], s[1]));
		if(adj[s[0]].find(s[1]) != adj[s[0]].end()){
			sozinho[0] = 2;
		}

		if(adj[s[1]].find(s[0]) != adj[s[1]].end()){
			sozinho[0] = 2;
		}

		adj[s[0]].insert(s[1]);
		adj[s[1]].insert(s[0]);
	}
}

int n;

int smallest_cycle(int v){
	queue<pii> fila;
	fila.push(mp(-1, v));
	int pr[170], dist[170], pai[170];
	fr(i, 170) {
		pr[i] = 0;
		dist[i] = 0;
	}

	int ans = n + 1;

	while(true){
		int davez = -1;

		while(!fila.empty()){
			if(!pr[fila.front().s]){
				pr[fila.front().s] = 1;
				
				if(fila.front().s != v){
					dist[fila.front().s] = dist[fila.front().f] + 1;
					pai[fila.front().s] = fila.front().f;
				}
				else{
					dist[fila.front().s] = 0;
					pai[fila.front().s] = fila.front().f;
				}
				davez = fila.front().s;
				fila.pop();
				break;
			}
			else{
				ans = min(ans, dist[fila.front().f] + dist[fila.front().s] + 1);
				fila.pop();
			}
		}

		if(davez == -1) break;

		for(int x: adj[davez]){
			if(!pr[x]){
				fila.push(mp(davez, x));
			}
			else if(pai[davez] != x){
				ans = min(ans, dist[x] + dist[davez] + 1);
			}
		}
	}
	/*
	fr(i, 5){
		cout << dist[i] << " ";
	}
	cout << endl;
	*/

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	crivo();
	cin >> n;
	fr(i, n){
		int x;
		cin >> x;
		build(x);

		if(quadrado || sozinho[0] > 1 || deu) break;
	}

	if(quadrado){
		cout << 1 << endl;
		return 0;
	}

	fr(i, p.size()){
		if(sozinho[i] > 1){
			cout << 2 << endl;
			return 0;
		}
	}

	fr(i, edges.size()){
		if(sozinho[edges[i].f] > 0 && sozinho[edges[i].s] > 0){
			cout << 3 << endl;
			return 0;
		}
	}

	int ans = n + 1;

	fr(i, 170){
		//cout << i << endl;
		int val = smallest_cycle(i);

		if(val < n+1){
			ans = min(ans, val);
		}
	}

	
	if(ans < n+1){
		cout << ans << endl;
	}
	else{
		cout << -1 << endl;
	}
}
