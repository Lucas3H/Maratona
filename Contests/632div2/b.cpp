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

	while(t--){
		int n;
		cin >> n;

		int a[MAXN], b[MAXN];
		frr(i, n) cin >> a[i];
		frr(i, n) cin >> b[i];

		int f1 = n, f2 = n;
		frm(i, n + 1){
			if(a[i] == 1) f1 = i;
			else if(a[i] == -1) f2 = i;
		}

		int deu = 1;

		frr(i, f1){
			if(a[i] < b[i]) deu = 0;
		}
		frr(i, f2){
			if(a[i] > b[i]) {
				deu = 0;
			}
		}

		if(deu) cout << "YES\n";
		else cout << "NO\n";

	}
}
