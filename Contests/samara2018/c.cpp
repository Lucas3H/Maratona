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
	int n;
	cin >> n;
	pii a[2*MAXN];

	frr(i, n){
		cin >> a[i].s >> a[i].f;
	}
	sort(a + 1, a + n + 1);

	vector<int> ans;

	int ind = 1;

	while(ind <= n){
		int aux = a[ind].f;
		ans.pb(a[ind].f);

		while(a[ind].s <= aux){
			ind++;
		}
	}

	cout << ans.size() << endl;
	for(int x: ans)
		cout << x<< " ";
	cout << endl;
}

