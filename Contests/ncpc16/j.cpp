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
typedef pair<long double, long double> ponto;
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
#define INF 1000000000000000100

int n, t;
vector<int> question[MAXN];
int resp[MAXN];
vector<vector<int>> trie;
long double p[101][MAXN];
long double P[101];

void build(int level){
	map<int, int> associate; // associa palavra com nó
	int vtx = 1;
	vector<vector<int>> aux; // Proximo leve;

	// Construo o proximo level
	for(auto node: trie){
		for(auto q: node){

			if(level <= question[q].size()){
				if(associate[question[q][level-1]] == 0){ // Se não foi feita ainda;
					associate[question[q][level-1]] = vtx++;
					vector<int> novo;
					novo.pb(q);

					aux.pb(novo);
				}
				else{
					int no = associate[question[q][level-1]] - 1;
					aux[no].pb(q);
				}
			}
		}

		associate.clear();
	}

	trie.clear();
	trie = aux;

	for(auto node: trie){
		multiset<int> fr;
		for(auto q: node){
			fr.insert(resp[q]);
		}

		int tam = fr.size();

		for(auto q: node){
			p[level][q] = (long double)(fr.count(resp[q]))/(tam);
		}
	}
}

map<string, int> wordInt;
int n_words = 1;

void readWord(int q){
	string s;
	cin >> s;
	if(wordInt[s] == 0){
		wordInt[s] = n_words++;
	}

	while(s.back() != '?'){
		question[q].pb(wordInt[s]);
		cin >> s;
	
		if(wordInt[s] == 0){
			wordInt[s] = n_words++;
		}
	}

	question[q].pb(wordInt[s]);

	cin >> s;
	if(wordInt[s] == 0)
		wordInt[s] = n_words++;

	resp[q] = wordInt[s];
}

void read(){
	cin >> t >> n;

	frr(i, n){
		readWord(i);
	}
}


int main(){
	read();
	fr(i, n + 1){
		fr(j, t + 1){
			p[i][j] = 1;
		}
	}

	int maximo = 0;
	vector<int> node0;

	frr(i, n){
		maximo = max(maximo, (int)question[i].size());
		node0.pb(i);
	}		

	trie.pb(node0);
	for(auto node: trie){
		multiset<int> fr;
		for(auto q: node){
			fr.insert(resp[q]);
		}

		int tam = fr.size();

		for(auto q: node){
			p[0][q] = (long double)(fr.count(resp[q]))/(tam);
		}
	}

	frr(i, maximo) {
		build(i);

		cout << "-----------Trie " << i << " ------------\n";
 
		for(auto node: trie){
			cout << "no novo" << endl;
			for(auto q: node){
				cout << q << " ";
			}
 
			cout << endl;
		}
		cout << "---------------------------\n\n\n";
	}

	frr(i, n){
		fr(j, t + 1){
			cout << p[j][i] << ' ';
		}
		cout << endl;	
	}


	fr(i, t + 1){
		frr(j, n){
			P[i] += p[i][j];
		}

		P[i] /= n;
	}

	long double e[101];
	fr(i, t + 1) e[i] = 0.0;
	e[1] = P[0];

	frr(i, t){
		fr(j, i){
			e[i] = max(e[i], e[i - j - 1] + P[j]);
		}
	}

	printf("%.7Lf\n", e[t]);
}

/*
	vector<int> aux;
	frr(i, n) aux.pb(i);

	trie.pb(aux);

	frr(i, 3){
		build(i);

		cout << "-----------Trie " << i << " ------------\n";

		for(auto node: trie){
			cout << "no novo" << endl;
			for(auto q: node){
				cout << q << " ";
			}

			cout << endl;
		}
		cout << "---------------------------\n\n\n";
	}
*/
