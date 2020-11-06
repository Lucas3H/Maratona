// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2255
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll, ll> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 105
#define MOD 1000000007

void bellman(vector<pair<ll, pii>> e, ll n){
	ll dist[MAXN][MAXN];

	fr(i, n + 1){
		fr(j, n + 1) dist[i][j] = MOD;
	}

	dist[0][0] = 0;

	fr(i, n){
		for(auto x: e){
			fr(j, n){
				if(dist[x.s.f][j] == MOD) continue;

				if(dist[x.s.s][j + 1] > dist[x.s.f][j] + x.f){
					dist[x.s.s][j + 1] = dist[x.s.f][j] + x.f;
				}
			}	
		}
	}

	int mini = MOD;
	fr(i, n + 1){
		if(dist[n-1][i] < mini) mini = dist[n-1][i];
		else dist[n-1][i] = mini;
	}

	int q;
	cin >> q;

	while(q--){
		ll maximo;
		cin >> maximo;
	//	cout << maximo << " || ";

		if(dist[n-1][min(maximo + 1, n)] == MOD) cout << "No satisfactory flights\n";
		else cout << "Total cost of flight(s) is $" << dist[n-1][min(maximo + 1, n)] << endl;

	}

}

int main(){
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	frr(ts, t){
		ll n;
		cin >> n;
//		cout << n << endl;

		map<string, ll> m;
		fr(i, n){
			string s;
			cin >> s;
//			cout << s << endl;

			m[s] = i;
		}

		vector<pair<ll, pii>> e;
		ll tot;
		cin >> tot;
//		cout << tot << endl;

		fr(i, tot){
			string s1, s2;
			ll w;
			cin >> s1 >> s2 >> w;
//			cout << s1 << " " << s2 << " " << w << endl;

			e.pb(mp(w, mp(m[s1], m[s2])));
		}

		cout << "Scenario #" << ts << endl;
		bellman(e, n);

		if(ts < t) cout << endl;
	}
}
