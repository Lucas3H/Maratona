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

#define MAXN 300010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n, m;
vector<int> pos[MAXN];	

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;

	frr(i, m){
		int a;
		cin >> a;
		pos[a].pb(i);
	}

	int mini[MAXN], maxi[MAXN];

	frr(i, n){
		mini[i] = i;
		maxi[i] = i;
		pos[i].pb(m+1);

		if(pos[i].size() == 1){
			maxi[i] = min(n, i + m);
		}
		else{
			mini[i] = 1;
			maxi[i] = max(maxi[i], min(i + pos[i][0] - 1, n));
			fr(j, pos[i].size() - 1){
				maxi[i] = max(maxi[i], min(pos[i][j+1] - pos[i][j], n));
			}
		}
	}

	frr(i, n){
		cout << mini[i] << ' ' << maxi[i] << endl;
	}
}
