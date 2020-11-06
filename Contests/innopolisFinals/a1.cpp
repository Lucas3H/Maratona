// 
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

int k;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin >> k >> s;

	pq<int> fila;
	fr(i, s.size()){
		pq<int> aux;
		while(!fila.empty() && fila.top() >= s[i]){
			aux.push(fila.top());
			fila.pop();
		}

		if(fila.empty()){
			k -= (s[i] - 'A');
			aux.push(s[i]);
		}
		else{
			k -= (s[i] - fila.top() - 1);
			fila.pop();
			aux.push(s[i]);

			while(fila.empty() == 0){
				aux.push(fila.top());
				fila.pop();
			}
		}

		fila = aux;
	}

	if(k < 0){
		cout << "Impossible\n";
	}
	else{
		cout << fila.size() << endl;
	}
}
