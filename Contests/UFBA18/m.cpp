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

int n;

vector<vector<pii>> op;

int tot = 0;

void divide(int tam){
	vector<pii> ans;
	for(int i = 1; i <= n; i+=tam){
		ans.pb({i, min(i + tam-1, n)}); 
	}

	tot += tam;

	op.pb(ans);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;

	int tam = (int)ceil((double)n/1000);
	tot += (tam - 1)*((int)ceil(log((double)n/1000)));


	while(tam < n && op.size() < 9){
		divide(tam);
		tam*=2;
	}	

	divide(n);

	cout << op.size() << endl;
	for(auto ans: op){
		cout << ans.size() << endl;
		for(auto x: ans){
			cout << x.f << " " << x.s << endl;
		}
	}

	/*
	cout << tot << " " << op.size() << endl;
	cout << tam << endl;
	*/
}
