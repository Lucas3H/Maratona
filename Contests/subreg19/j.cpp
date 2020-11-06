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
#define INF 1000000000000000100

int c[20][4];
int n, k;
map<char, int> aux;
int coringa = 0;
int carta_passada = 0;
int deu = 0;

void read(){
	for(int i = 2; i <= 9; i++){
		aux[char('0' + i)] = i;
	}
	aux['A'] = 1;
	aux['D'] = 10;
	aux['Q'] = 11;
	aux['J'] = 12;
	aux['K'] = 13;

	cin >> n >> k;

	coringa = 2*k;

	frr(i, n){
		string s;
		cin >> s;

		fr(j, 4){
			c[i][j] = aux[s[j]];
		}

		sort(c[i], c[i] + 4);
		if(c[i][0] == c[i][3] && deu == 0 && i != k){
			deu = i;
		}
	}
}

int func(int ind){
	if(carta_passada == 0){
		coringa = ind;

		sort(c[ind], c[ind] + 4);

		fr(i, 4){
			//cout << c[ind][i] << " "; 
		}

		if(c[ind][0] == c[ind][2]){
			carta_passada = c[ind][3];
			c[ind][3] = 0;
		}
		else if(c[ind][1] == c[ind][3]){
			carta_passada = c[ind][0];
			c[ind][0] = 0;
		}
		else if(c[ind][2] == c[ind][3] || c[ind][1] == c[ind][2]){
			carta_passada = c[ind][0];
			c[ind][0] = 0;
		}
		else if(c[ind][0] == c[ind][1]){
			carta_passada = c[ind][2];
			c[ind][2] = 0;
		}
		else{
			carta_passada = c[ind][0];
			c[ind][0] = 0;	
		}

		return 0;
	}
	
	if(coringa == ind){
		sort(c[ind], c[ind] + 4);
		c[ind][0] = carta_passada;
		carta_passada = 0;
	}
	else{
		map<int, int> fr;
		fr(i, 4) fr[c[ind][i]]++;
		fr[carta_passada]++;

		vector<pair<int, int>> s;
		for(auto x: fr){
			s.pb({x.s, x.f});
		}
		sort(s.begin(), s.end());

		carta_passada = s[0].s;
		s[0].f--;

		int cont = 0;
		for(auto x: s){
			fr(j, x.f){
				c[ind][cont++] = x.s;
			}
		}
	}


	sort(c[ind], c[ind] + 4);
	if(c[ind][0] == c[ind][3]) return 1;
	else return 0;
}

int main(){
	ios::sync_with_stdio(false);
	read();

	if(deu > 0){
		cout << deu << endl;
		return 0;
	}

	int davez = k;
	while(func(davez) == 0){
		//cout << davez << " " << carta_passada << endl;
		davez++;
		if(davez == n+1) davez = 1;
	}

	cout << davez << endl;
}
