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
		int n;
		cin >> n;

		int m[110][110];
		frr(i, n){
			frr(j, n) cin >> m[i][j];
		}

		int l = 0, c = 0;
		frr(i, n){
			set<int> s;
			frr(j, n){
				s.insert(m[i][j]);
			}

			if(s.size() < n) l++;
		}

		frr(i, n){
			set<int> s;
			frr(j, n){
				s.insert(m[j][i]);
			}

			if(s.size() < n) c++;
		}

		int tr = 0;
		frr(i, n){
			tr+=m[i][i];
		}

		cout << "Case #" << ts << ": " << tr << " " << l << ' ' << c << endl;
	}
}
