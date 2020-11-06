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

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

int pr[MAXN];
vector<int> adj[MAXN];
void dfs(int v){
	pr[v] = 1;

	for(auto x: adj[v]){
		if(!pr[x]) dfs(x);
	}
}

vector<int> l[30];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	fr(i, n){
		string s;
		cin >> s;
		int st = s.size();
		fr(j, st){
			l[s[j] - 'a'].pb(i);
		}
	}

	fr(i, 26){
		int t = l[i].size();
		fr(j, t - 1){
			adj[l[i][j]].pb(l[i][j+1]);
			adj[l[i][j + 1]].pb(l[i][j]);
		}

		//cout << t << endl;
	}


	int ans = 0;
	fr(i, n){
		if(!pr[i]){
			dfs(i);
			ans++;
		}
	}

	cout << ans << endl;
}
