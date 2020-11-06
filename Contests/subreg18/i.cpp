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

int est[1010];
int n, m, l;
	
bool off(){
	for(int i = 1; i <= m; i++){
		if(est[i]) return false;
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> m >> l;

	fr(i, l){
		int aux = 0;
		cin >> aux;
		est[aux] = 1;
	}

	vector<int> v[1010];
	fr(i, n){
		int k;
		cin >> k;
	
		fr(j, k){
			int aux;
			cin >> aux;

			v[i].pb(aux);
		}
	}

	int deu = 0;
	for(int i = 0; i < 2*n; i++){
		if(off()){
			cout << i << endl;
			return 0;
		} 

		for(auto x: v[i%n]){
			est[x] =  1 - est[x];
		}
	}
	
	if(off()){
		cout << 2*n << endl;
		return 0;
	} 
	else cout << -1 << endl;
}
