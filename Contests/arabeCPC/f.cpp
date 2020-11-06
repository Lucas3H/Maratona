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

double e[350][350], prob[350][350];
int n, k, tot = 0;

int find(int x){
	if(x == 1) return 1;
	int ans = 0;
	for(int i = x-1; i >= 1; i--){
		ans+=i*x;
	}

	return 2*ans + find(x-1) + x*x;
}

int main(){
	//ios::sync_with_stdio(false);

	freopen("fetiera.in", "r", stdin);
	int t;
	cin >> t;

	while(t--){
		cin >> n >> k;
		frr(i, n){
			frr(j, n){
				e[i][j] = 0.0;
				prob[i][j] = 0.0;
			}
		}

		frr(i, n){
			frr(j, n){
				cin >> e[i][j];
			}
		}

		tot = find(n);

		//cout << tot << endl;

		frr(i, n){
			frr(j, n){
				prob[i][j] = (double)(i*j*(n - i + 1)*(n - j + 1))/tot;
				//cout << prob[i][j] << " ";
			}
			//cout << endl;
		}

		while(k--){
			frr(i, n){
				frr(j, n){
					e[i][j] = (1 - e[i][j])*prob[i][j] + (1 - prob[i][j])*e[i][j];
				}
			}
		}

		double resp = 0.0;
		frr(i, n){
			frr(j, n){
				resp += e[i][j];
			}
		}

		printf("%.5lf\n", resp);


	}
}
