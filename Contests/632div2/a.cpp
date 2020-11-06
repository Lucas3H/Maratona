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
		int n, m;
		cin >> n >> m;

		char a[110][110];

		if((n*m)%2 == 1){
			fr(i, n){
				fr(j, m){
					if((i+j)%2 == 0)a[i][j] = 'B';
					else a[i][j] = 'W';
				}
			}
		}
		else{
			fr(i, n){
				fr(j, m){
					if((i+j)%2 == 0)a[i][j] = 'B';
					else a[i][j] = 'W';
				}
			}
			
			if(a[n-1][m-1] =='W') a[n-1][m-1] = 'B';
			else {
				fr(i, n){
					fr(j, m){
						if((i+j)%2 == 0)a[i][j] = 'W';
						else a[i][j] = 'B';
					}
				}
				
				a[n-1][m-1] = 'B';	
			}
		}

		fr(i, n){
			fr(j, m) cout << a[i][j];
			cout << endl;
		}
	}
}
