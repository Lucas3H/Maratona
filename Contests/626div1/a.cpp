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

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n, sum[MAXN];
char v[MAXN];
int aux[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	frr(i, n) cin >> v[i];

	frr(i, n){
		if(v[i] == '(') sum[i] = sum[i-1] + 1;
		else sum[i] = sum[i-1] - 1;

		if(sum[i] == -1){
			if(sum[i-1] == 0) aux[i] = -1;
		}

		if(sum[i] == 0){
			if(sum[i-1] == -1) aux[i] = 1;
		}
	}

	int ans = 0, atu = 0;
	frr(i, n){
		if(aux[i] == -1 && atu == 0){
			atu = -1;
		}

		if(atu == -1){
			ans++;
		}

		if(aux[i] == 1){
			atu = 0;
		}
	}

	if(sum[n] == 0) cout << ans << endl;
	else cout << -1 << endl;
}
