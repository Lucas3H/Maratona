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

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;

		int deu = 1, tipo = -1;
		fr(i, s.size()){
			if(s[i] == '1') deu = 0;
		}

		if(deu == 1){
			tipo = 0;
		}

		deu = 1;

		fr(i, s.size()){
			if(s[i] == '0') deu = 0;
		}

		if(deu == 1){
			tipo = 1;
		}

		if(tipo == 0){
			fr(i, s.size()) cout << 0;
			cout << endl;
		}
		else if(tipo == 1){
			fr(i, s.size()) cout << 1;
			cout << endl;
		}
		else{
			fr(i, s.size()){
				cout << 10;
			}

			cout << endl;
		}
	}
}
