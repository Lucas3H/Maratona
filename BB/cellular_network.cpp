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

int n, m;
int towers[MAXN], p[MAXN];

int findR(int ind){
	if(p[ind] < towers[1])
		return towers[1] - p[ind];
	else if(p[ind] > towers[m])
		return p[ind] - towers[m];

	int ini = 1, fim = m, mid;

	while(ini < fim - 1){
		mid = (ini + fim)/2;

		if(towers[mid] > p[ind])
			fim = mid;
		else if(towers[mid] == p[ind])
			return 0;
		else
			ini = mid;
	}

	return min(towers[fim] - p[ind], p[ind] - towers[ini]);
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> m;
	frr(i, n) cin >> p[i];
	frr(i, m) cin >> towers[i];

	sort(towers + 1, towers + m + 1);

	int ans = 0;
	frr(i, n){
		ans = max(ans, findR(i));
	}

	cout << ans << endl;
}
