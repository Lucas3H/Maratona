#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
		ios::sync_with_stdio(false);

		int tests;
		cin >> tests;

		while(tests--){
				int n, m, k;
				cin >> n >> m >> k;

				int h[110];
				fr(i, n) cin >> h[i];

				int deu = 1;
				frr(i, n-1){
						if(h[i-1] >= h[i] - k){
								m += h[i-1] - max(h[i] - k, 0);
						}
						else{
								if(m >= h[i] - k - h[i-1]){
										m-= h[i] - k - h[i-1];
								}
								else deu = 0;
						}
				}

				if(deu){
						cout << "YES" << endl;
				}
				else cout << "NO" << endl;
		}

}
