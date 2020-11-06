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

map<int, int> fib;
int f[1000010];

void build(){
	f[1] = 1;
	f[2] = 1;
	fib[1] = 2;

	for(int i = 3; f[i-1] + f[i-2] < 1000010; i++){
		f[i] = f[i-1] + f[i-2];
		fib[f[i]] = i;
	}
}

vector<int> k[1000010];

int main(){
	ios::sync_with_stdio(false);
	build();
	int n;
	cin >> n;

	frr(i, n){
		int m;
		cin >> m;

		if(fib[m] != 0){
			k[fib[m]].pb(i);
		}
	}

	if(k[2].size() > 1){
		cout << k[2][0] <<' ' << k[2][1] << endl;
	}
	else{
		frr(i, 1000000){
			if(k[i].size() > 0 && k[i+1].size() > 0){
				cout << k[i][0] << " " << k[i+1][0] << endl;
				return 0;
			}
		}

		cout << "impossible\n";
	}
}
