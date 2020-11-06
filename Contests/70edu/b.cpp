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

int m[11][11][11];

int main(){
		ios::sync_with_stdio(false);

    mem(m, -1);

    fr(i, 10){
      fr(j, 10){
        frr(k, 10) {
					if(m[i][j][(k*i)%10] == -1) m[i][j][(k*i)%10] = k;
					else m[i][j][(k*i)%10] = min(k, m[i][j][(k*i)%10]);
				}
			}
    }

		fr(i, 10){
      fr(j, 10){
        frr(k, 10) {
					if(m[i][j][(k*j)%10] == -1) m[i][j][(k*j)%10] = k;
					else m[i][j][(k*j)%10] = min(k, m[i][j][(k*j)%10]);
				}
			}
    }

    fr(i, 10){
      fr(j, 10){
        fr(k, 10){
          frr(l, 10){
						if(m[i][j][k] == -1) continue;

						if(m[i][j][(k + j*l)%10] == -1) m[i][j][(k + j*l)%10] = m[i][j][k] + l;
            else m[i][j][(k + j*l)%10] = min(m[i][j][(k + j*l)%10], m[i][j][k] + l);
          }
        }
      }
    }

    string s;
		cin >> s;

		fr(i, 10){
			fr(j, 10){
				int ans = 0;
				frr(k, s.size() - 1){
					int l = (s[k] - s[k-1] + 10)%10;

					if(m[i][j][l] == -1){
						ans = -1;
						break;
					}

					ans += m[i][j][l];
				}

				if(ans == -1) cout << -1 << " ";
				else cout << ans - s.size() + 1 << " ";
			}

			cout << endl;
		}
}
