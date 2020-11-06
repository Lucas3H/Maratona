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

const int MAX = (1 << 24) + 10;


int dp[MAX];
int d[30][30];
int n;
int xO[30], yO[30];
int x, y;
int dHand[30];
int pai[MAX];

void read(){
	cin >> x >> y;
	cin >> n;
	fr(i, n){
		cin >> xO[i] >> yO[i];
	}

	fr(i, n){
		fr(j, n){
			d[i][j] = (xO[i] - xO[j])*(xO[i] - xO[j]) + (yO[i] - yO[j])*(yO[i] - yO[j]);
		}
	}

	fr(i, n){
		dHand[i] = (xO[i] - x)*(xO[i] - x) + (yO[i] - y)*(yO[i] - y);
	}

	fr(i, (1 << n)) dp[i] = MOD;
}

void solve(){
	dp[0] = 0;
	fr(mask, (1 << n) - 1){
		int i = 0, menor;
		while(i < n){
			if((mask & (1 << i)) == 0){
				menor = i;
				i++;
				break;
			}
			i++;
		}

		int m = mask;
		m|=(1 << menor);

		if(dp[m] > dp[mask] + 2*dHand[menor]){
			dp[m] = dp[mask] + 2*dHand[menor];
			pai[m] = mask;
		}

		while(i < n){
			if((mask & (1 << i)) == 0){
				if(dp[(m | (1 << i))] > dp[mask] + dHand[menor] + dHand[i] + d[i][menor]){
					dp[(m | (1 << i))] = dp[mask] + dHand[menor] + dHand[i] + d[i][menor];
					pai[(m | (1 << i))] = mask;
				}
			}

			i++;
		} 
	}
}

void findAns(){
	vector<int> v;
	v.pb(0);
	int davez = ((1 << n) - 1);

	while(davez > 0){
		int p = pai[davez];

		fr(i, n){
			if(((1 << i) & p) == 0 && (((1 << i) & davez)) > 0){
				v.pb(i + 1);
			}
		}

		v.pb(0);
		davez = p;
	}

	frm(i, v.size()){
		cout << v[i] << " ";
	}

	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	read();

	solve();
	cout << dp[(1 << n) - 1] << endl;
	findAns();
}	
