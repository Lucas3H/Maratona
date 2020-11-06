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

int x[1010];
double c[1010];
int n, r;


int main(){
	cin >> n >> r;
	frr(i, n) cin >> x[i];

	frr(i, n){
		c[i] = r;

		for(int j = 1; j < i; j++){
			int d = x[i] - x[j];
			c[i] = max(c[i], c[j] + sqrt(4*r*r - d*d));
		}
	}

	frr(i, n) printf("%.7lf ", c[i]);
	cout << endl;

}
