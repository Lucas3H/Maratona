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

#define MAXN 100000
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

vector<pii> v[MAXN];
ll ans;

int main(){
	ios::sync_with_stdio(false);

	frr(ts, t){
		ll r, c;
		cin >> r >> c;

		ll m[r + 1][c + 1];

		ans = 0
		frr(i, 1000000) v[i].clear();

		frr(i, r){
			frr(j, c){
				cin >> m[i][j];
				v[m[i][j]].pb(i, j);
			}
		}
	
		frr(i, 1000000){
			for(auto x: v[i]){
				if
			}
		}
	}
}