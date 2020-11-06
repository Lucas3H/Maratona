// 
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

int n, k;
pair<pii, int> find(){
	frr(i, n){
		frr(j, n){
			frr(l, n){
				if(i*j + (n - i)*l == k){
					return mp(mp(i, j), k);
				}
			}
		}
	}

	return mp(mp(-1, -1), -1);
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	frr(ts, t){
		cin >> n >> k;

		cout << "Case #" << ts << ": ";
		set<int> s;
		frr(i, n) s.insert(i);
		int v[110], f[110];
		int ans[110][110];

		pair<pii, int> p = find();

		if(p.f.f == -1){
			cout << "IMPOSSIBLE\n";
			continue;
		}

		int l1 = p.f.s;
		int a = p.f.s, b = p.s;

		if(a == b){
			frr(i, n){
				frr(j, n){
					cout << (i + j - 3 + a)%n + 1 << " ";
				}

				cout << endl;
			}

			continue;
		}

		v[0] = a;
		v[1] = b;

		s.erase(a);
		s.erase(b);

		for(int i = 2; i < tam; i++){
			v[i] = (*s.begin());
			s.erase(v[i]);
		}

		for(int i = 0; i < n - tam; i++){
			f[i] = (*s.begin());
			s.erase(v[i]);
		}

		fr(i, tam){
			fr(j, tam){
				m[i][j] = v[(i + j)%n];
			}

			fr(j, n - tam){
				m[i][j] = v[(i + j)%n];
			}
		}
		fr(i, n - tam){

		}
	}
}
