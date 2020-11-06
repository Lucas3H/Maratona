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
	int r, k;
	cin >> k >> r;

	int n = (1 << k) - r;

	double ret = 0.0;

	for(int i = 1; i <= 20 && i <= k && n >= (1 << i) - 1; i++){
		int x = n;
		int y = (double)((1 << k) - 1);

		double termo = 1.0;

		for(int j = 0; j <= (1 << i) - 2; j++){
			termo *= (double)(x - j)/(y - j);
		}

		ret += termo;
	}

	printf("%.5lf\n", ret);
}
