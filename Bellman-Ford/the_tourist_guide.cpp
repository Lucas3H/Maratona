// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1040 
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

int n, r;

void bellman(vector<pair<int, pii>> e, int n, int s, int d, int t){
	vector<int> dist(n + 1, MOD);

	dist[s] = MOD-1;

	fr(i, n-1){

		for(auto x: e){
			if(dist[x.s.f] == MOD && dist[x.s.s] == MOD) continue;
			else if(dist[x.s.f] == MOD && x.s.f != s) {
				if(x.s.f != s){
					dist[x.s.f] = min(x.f, dist[x.s.s]);
				}
			}
			else if(dist[x.s.s] == MOD && x.s.s != s){
				if(x.s.s != s){
					dist[x.s.s] = min(x.f, dist[x.s.f]);
				}
			}
			else{
				if(x.s.s == s){
					dist[x.s.f] = max(dist[x.s.f], min(x.f, dist[x.s.s]));
				}
				else if(x.s.f == s){
					dist[x.s.s] = max(dist[x.s.s], min(x.f, dist[x.s.f]));
				}
				else if(x.s.s != s && x.s.f != s){
					dist[x.s.s] = max(dist[x.s.s], min(x.f, dist[x.s.f]));
					dist[x.s.f] = max(dist[x.s.f], min(x.f, dist[x.s.s]));
				}
			}
		}
	}

	cout << "Minimum Number of Trips = " << ceil((double)t/(dist[d] - 1)) << endl << endl;
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> r;
	int sc = 1;

	while(n != 0 ||r != 0){
		vector<pair<int, pii>> e;
	
		fr(i, r){
			int v1, v2, w;
			cin >> v1 >> v2 >> w;

			e.pb(mp(w, mp(v1, v2)));
		}

		int s, d, t;
		cin >> s >> d >> t;

		cout << "Scenario #" << sc++ << endl;
		bellman(e, n, s, d, t);


		cin >> n >> r;
	}
}
