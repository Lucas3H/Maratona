// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
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
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int bellman(vector<pair<int, pii>> e, int n){
	vector<int> dist(n, MOD);
	dist[0] = 0;

	int any = 0;
	fr(i, n){
		any = 0;

		for(auto x: e){
			

			if(dist[x.s.f] == MOD) continue;

			if(dist[x.s.s] > dist[x.s.f] + x.f){
				dist[x.s.s] = dist[x.s.f] + x.f;
				any = 1;
			}
		}

	}

	if(any) return 1;
	else return 0;
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		int n, m;
		cin >> n >> m;

		int v1, v2, w;
		vector<pair<int, pii>> e;

		fr(i, m){
			cin >> v1 >> v2 >> w;
			e.pb(mp(w, mp(v1, v2)));
		}

		if(bellman(e, n)) cout << "possible" << endl;
		else cout << "not possible" << endl;
	}
}
