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

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

set<int> adj[MAXN];
int v[MAXN];
int ultimo[MAXN];

int main(){
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	frr(i, n){
		cin >> v[i];
		adj[v[i]].insert(i);
		ultimo[v[i]] = max(ultimo[v[i]], i);
	}

	vector<pii> ans;

	int aux = *(adj[1].begin());
	int maior = aux;

	ans.pb(mp(aux, 1));

	for(int i = 2; i <= k; i++){
		auto l = upper_bound(adj[i].begin(), adj[i].end(), maior);

		if(l == adj[i].end()){
			ans.pb(mp(ultimo[i], i));
			maior = max(maior, ultimo[i]);
		}
		else{
			aux = *(l);
			ans.pb(mp(aux, i));
			maior = max(maior, aux);
		}
	}

	sort(ans.begin(), ans.end());

	fr(i, ans.size()){
		cout << ans[i].s << " ";
	}

	cout << endl;
}
