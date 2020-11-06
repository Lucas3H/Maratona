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

int sup = MOD;
int inf = 0;
int n;

int a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	frr(i, n) cin >> a[i];

	int sum = 0;
	frr(i, n){
		if(i%2 == 1){
			sum = a[i]-sum;
			sup = min(sup, sum);
		}
		else{
			sum = a[i]-sum;
			inf = max(inf, -sum);		
		}

	//	cout << sum << endl;
	}

	//cout << sup << ' ' << inf << endl;
	if(sup < inf) cout << 0 << endl;
	else cout << sup - inf + 1 << endl;

}
