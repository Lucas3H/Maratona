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

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	frr(ts, t){
		pair<pii, int> v[2010];

		int n;
		cin >> n;

		frr(i, n){
			int s, e;
			cin >> s >> e;
			v[2*i - 1] = mp(mp(s, 1), i);
			v[2*i] = mp(mp(e, 0), i);
		}

		char ans[1010];
		sort(v + 1, v + 2*n + 1);

		int j = 0, c = 0, deu = 1;
		frr(i, 2*n){
			if(v[i].f.s == 1){
				if(j == 0){
					j = v[i].s;
					ans[v[i].s] = 'J';
				}
				else if(c == 0){
					c = v[i].s;
					ans[v[i].s] = 'C';
				}
				else{
					deu = 0;
					break;
				}
			}
			else{
				if(j == v[i].s)
					j = 0;
				else
					c = 0;
			}

			//cout << j << " " <<c << " " << v[i].f.f <<" " << v[i].f.s <<" " << v[i].s << endl;
		}


		cout << "Case #" << ts << ": ";
		if(deu){
			frr(i, n){
				cout << ans[i];
			}
			cout << endl;
		}
		else{
			cout << "IMPOSSIBLE\n";
		}
	}
}
