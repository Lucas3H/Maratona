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
	if(n < 3){
		cout << -1 << endl;
		return 0;
	}

	int ans[510][510];
	int davez = 1;
	for(int j = 1; j <= (n-4); j+=2){

		int side = (n - j + 1);
		int lin = 1, col = j;

		for(int i = 1; i <= side; i++){
			ans[lin++][col] = davez++;
		}

		lin--;

		for(int i = 1; i < side; i++){
			ans[lin][++col] = davez++;
		}

		side--;
		lin--;

		for(int i = 1; i <= side; i++){
			ans[lin][col--] = davez++;
		}

		col++;

		for(int i = 1; i < side; i++){
			ans[--lin][col] = davez++;
		}
	}

	if(n%2 == 0){
		int side = 4;
		int lin = 1, col = n-3;

		for(int i = 1; i <= side; i++){
			ans[lin++][col] = davez++;
		}

		lin--;

		for(int i = 1; i < side; i++){
			ans[lin][++col] = davez++;
		}
	}

	if(n%2 == 0){
		ans[1][n] = davez++;
		ans[2][n] = davez++;
		ans[3][n-1] = davez++;
		ans[3][n-2] = davez++;
		ans[1][n-2] = davez++;
		ans[1][n-1] = davez++;
		ans[3][n] = davez++;
		ans[2][n-1] = davez++;
		ans[2][n-2] = davez++;
	}
	else{
		ans[1][n-2] = davez++;
		ans[2][n-2] = davez++;
		ans[3][n-1] = davez++;
		ans[3][n] = davez++;
		ans[1][n] = davez++;
		ans[1][n-1] = davez++;
		ans[3][n-2] = davez++;
		ans[2][n-1] = davez++;
		ans[2][n] = davez++;
	}

	frr(i, n){
		frr(j, n) cout << ans[i][j] << " ";
		cout << endl;
	}

}