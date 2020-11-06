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

vector<int> adj[MAXN];
int prince[MAXN];

void solve(){
	cin >> n;

	frr(i, n){
		prince[i] = 0;
		adj[i].clear();
	}

	int deu_ruim = 0;

	frr(i, n){
		int k, g;
		cin >> k;

		int deu = 0;
		fr(j, k){
			cin >> g;
			if(prince[g] == 0 && deu == 0){
				prince[g] = i;
				deu = 1;
			}
		}

		if(deu == 0){
			deu_ruim = i;
		}
	}

	if(deu_ruim > 0){
		cout << "IMPROVE\n";
		frr(i, n){
			if(prince[i] == 0){
				cout << deu_ruim << " " << i << endl;
				break;
			}
		}
	}
	else{
		cout << "OPTIMAL\n";
	}
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		solve();
	}
	
}
