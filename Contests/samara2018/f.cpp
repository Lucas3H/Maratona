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
vector<int> adj[1010], des[1010], anc[1010];
int deu = 1, raiz = -1;

void read(){
	cin >> n;
	frr(i, n){
		int a;
		cin >> a;

		fr(j, a){
			int k;
			cin >> k;
			des[i].pb(k);
			anc[k].pb(i);
		}
	}
}

void build(){
	frr(i, n){
		if(des[i].size() == n) {
			deu = 0;
			return;
		}
		if(des[i].size() == n-1){
			if(raiz == -1) raiz = i;
			else {
				deu = 0;
				return;
			}
			continue;
		}

		if(anc[i].size() == 0) {
			deu = 0;
    		return;
    	}
      
		int menor = anc[i][0];
		fr(j, anc[i].size()){
			if(des[anc[i][j]].size() < des[menor].size()){
				menor = anc[i][j];
			}
		}

//		cout << menor << " " << i << endl;

		adj[menor].pb(i);
	}
}

void check(){
	if(raiz == -1){
		deu = 0;
		return;
	}

	fr(i, n-1){
		if(des[raiz][i] == raiz){
			deu = 0;
			return;
		}
	}

  	if(deu == 0) return;

	frr(i, n){
		if(i == raiz) continue;

		int fr[1010];
		frr(j, n) fr[j] = 0;

		for(auto x: adj[i]){
			for(auto y: des[x]){
				fr[y]++;
			}
			fr[x]++;
		}

		for(auto x: des[i]){
			fr[x]--;
		}

		frr(j, n){
			if(fr[j] != 0){
				deu = 0;
				return;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	read();
	build();
	check();

	if(deu){
		cout << "YES\n";
		frr(i, n){
			for(int x: adj[i]){
				cout << i << " " << x<< endl;
			}
		}
	}
	else{
		cout << "NO\n";
	}
}
