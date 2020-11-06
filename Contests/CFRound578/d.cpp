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

int m[2010][2010];

		int ans[2010][2010];

int main(){
		ios::sync_with_stdio(false);

		int n, k;
		cin >> n >> k;

		string s;
		fr(i, n){
				cin >> s;

				fr(j, n){
						if(s[j] == 'B') m[i][j] = 1;
						else m[i][j] = 0;
				}
		}

		vector<pii> vertical;
		vector<pii> horizontal;

		int w = 0;

		fr(i, n){
				int ini = -1, fim = -1;

				fr(j, n){
						if(ini == -1 && m[i][j] == 1) ini = j;
						if(m[i][j] == 1) fim = j;
				}

				if(ini == -1){
						w++;
						continue;
				}


									if(fim - ini + 1 > k) continue;

				for(int l = max(0, fim - k + 1); l <= ini; l++){
						for(int j = max(0, i - k + 1); j <= i; j++) {
							ans[j][l]++;

						}
				}/*

				horizontal.pb(mp(max(0, fim - k + 1) ,ini));
				vertical.pb(mp(max(i - k + 1, 0), i));
		*/}

		fr(j, n){
				int ini = -1, fim = -1;

				fr(i, n){
						if(ini == -1 && m[i][j] == 1) ini = i;
						if(m[i][j] == 1) fim = i;
				}


								if(ini == -1){
										w++;
										continue;
								}

					if(fim - ini + 1 > k) continue;

				for(int l = max(0, j - k +1); l <= j; l++){
						for(int i = max(0, fim - k + 1); i <= ini; i++){
								ans[i][l]++;
 						}
				}

			//	horizontal.pb(mp(max(0, j - k + 1)), i)
		}

		int maior = 0;
		fr(i, n){
				fr(j, n){
						//cout << ans[i][j] << " ";
						if(ans[i][j] > maior) maior = ans[i][j];
				}

				//cout << endl;
		}

		cout << maior + w << endl;
}
