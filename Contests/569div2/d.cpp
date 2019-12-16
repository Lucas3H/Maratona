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
		int n, m;
		scanf("%d %d", &n, &m);

		if(n < m){
			frr(i, n/2){
					frr(j, m){
								printf("%d %d\n", i, j);

								printf("%d %d\n", n - i + 1, m - j + 1);
					}
			}

			if(n%2 == 1){

					frr(j, m/2){
							printf("%d %d\n", n/2 + 1, j);
							printf("%d %d\n", n/2 + 1, m - j + 1);
					}


					if(m%2 == 1){
							printf("%d %d\n", n/2 + 1, m/2 + 1);
					}
			}
		}
		else{
			frr(i, m/2){
					frr(j, n){
								printf("%d %d\n", j, i);

								printf("%d %d\n", n - j + 1, m - i + 1);
					}
			}

			if(m%2 == 1){

					frr(j, n/2){
							printf("%d %d\n", j, m/2+1);
							printf("%d %d\n", n - j + 1, m/2+1);
					}


					if(n%2 == 1){
							printf("%d %d\n", n/2 + 1, m/2 + 1);
					}
			}
		}

		return 0;
}
