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

double dist(int a, int b, int c, int d){
	return sqrt((a - b)*(a - b) + (c - d)*(c - d));
}

int main(){
	ios::sync_with_stdio(false);
	int x[2], y[2];
	int a, b;
	cin >> a >> b;
	cin >> x[0] >> y[0] >> x[1] >> y[1];

	if(x[0] > x[1]) swap(x[0], x[1]);
	if(y[0] > y[1]) swap(y[0], y[1]);



	if(x[0] <= a && a <= x[1]) printf("%.3lf\n", (double)min(abs(b - y[0]), abs(b - y[1])));
	else if(y[0] <= b && b <= y[1]) printf("%.3lf\n", (double)min(abs(a - x[0]), abs(a - x[1])));
	
	else{
		double l[4];

		l[0] = dist(a, x[0], b, y[0]);
		l[1] = dist(a, x[1], b, y[0]);
		l[2] = dist(a, x[0], b, y[1]);
		l[3] = dist(a, x[1], b, y[1]);

		double mini = min(l[0], min(l[1], min(l[2], l[3])));

		printf("%.3lf\n", mini);
	}
}