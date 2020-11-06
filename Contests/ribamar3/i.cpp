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

vector<pair<char, pair<char, int>>> v;

void read(){
	char op;
	cin >> op;

	while(op != 'E'){
		int a;
		char l = '\n';	
		if(op == 'D'){
			cin >> a;
		}
		else{
			cin >> a >> l;
		}

		v.pb(mp(op, mp(l, a)));

		cin >> op;
	}
}

void buildBIT(){
	vector<pii> posicoes;
	posicoes.pb(mp(0, -1));

	fr(j, v.size()){
		pair<char, pair<char, int>> x = v[j];
		vector<pii> aux;
		int colocado = 0;

		fr(i, posicoes.size()){
			if(x.s.s > posicoes[i].f){
				aux.pb(posicoes[i]);
			}
			else if(x.s.s == posicoes[i].f){
				break;
			}
			else{	
				if(colocado){
					aux.pb(mp(posicoes[i].f + 1, posicoes[i].s));
				}
				else{
					aux.pb(mp(x.s.s, j));
					aux.pb(mp(posicoes[i].f + 1, posicoes[i].s));	
				}

				colocado = 1;	
			}
		}
		posicoes = aux;
	}

	fr(i, posicoes.size()) cout << posicoes[i].f << endl;
}

int main(){
	ios::sync_with_stdio(false);

	read();
	buildBIT();
}
