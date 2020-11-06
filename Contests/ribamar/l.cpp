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

string n;
int tam, ini;
int a[50];
int inv[5] = {0, 1, 3, 2, 4};


bool check(){
	/*
	fr(i, (tam + 1)/2){
		cout << a[i];
	}

	cout << endl;
	*/
	fr(i, tam){
		int sum = 0;

		fr(j, i + 1){
			sum += a[j]*a[i - j];
		}

		sum = (sum)%10;


		sum = (sum)%10;

		//cout << n[i] - '0' << endl;

		if(sum != (int)(n[i] - '0')){
			return 0;
		}
	}

	return 1;
}

void recursao(int d){

	if(d + ini >= tam){
		if(check()){
			fr(i, (tam + 1)/2) cout << a[i];
			cout << endl;

			exit (0);
		}

		return;
	}

	int aux = n[ini + d] - '0';

	for(int j = 1; j < ini + d; j++){
		if(j == d || (ini + d - j) == d) continue;

		aux = (aux - (a[j]*a[ini + d - j])%10 + 10)%10;
	}

	if(aux%2 != 0){
		return;
	}

	a[d] = (aux*(inv[(a[ini]*2)%5]))%5;

	recursao(d + 1);

	a[d] = (aux*inv[(a[ini]*2)%5])%5 + 5;

	recursao(d + 1);	
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;

	tam = n.size();

	if(n.size()%2 == 0){
		cout << -1 << endl;
		return 0;
	}

	ini = 0;

	while(2*ini < tam){
		if(n[2*ini] == '0'){
			a[ini] = 0;

			if(2*ini == tam - 1){
				fr(i, (tam + 1)/2) cout << a[i];
				cout << endl;

				exit (0);
			}
			else if(n[2*ini+1] != '0'){
				cout << -1 << endl;
				return 0;
			}

			ini++;
		}
		else if(n[2*ini] == '5'){
			a[ini] = 5;
			/*
			db;

			cout << 2*ini << endl;
			*/
			if(2*ini == tam - 1){
				fr(i, (tam + 1)/2) cout << a[i];
				cout << endl;

				exit (0);
			}
			else if(n[2*ini+1] != '0'){
				cout << -1 << endl;
				return 0;
			}

			ini++;
		}
		else if(n[2*ini] == '1' || n[2*ini] == '4' || n[2*ini] == '9' || n[2*ini] == '6'){
			break;
		}
		else{
			cout << -1 << endl;
			return 0;
		}
	}

	/*
	fr(i, ini) cout << a[i];
	cout << endl;
	*/


	if(n[2*ini] == '4'){
		a[ini] = 2;

		recursao(ini+1);

		a[ini] = 8;

		recursao(ini+1);
	}
	else if(n[2*ini] == '1'){
		a[ini] = 1;

		recursao(ini+1);

		a[ini] = 9;

		recursao(ini+1);	
	}
	else if(n[2*ini] == '9'){
		a[ini] = 3;

		recursao(ini+1);

		a[ini] = 7;

		recursao(ini+1);		
	}
	else if(n[2*ini] == '6'){
		a[ini] = 4;

		recursao(ini+1);

		a[ini] = 6;

		recursao(ini+1);	
	}

	cout << -1 << endl;
}
