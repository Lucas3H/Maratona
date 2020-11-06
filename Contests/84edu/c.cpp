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

int n, m, k;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;

	fr(i, 2*k){
		int x, y;
		cin >> x >> y;
	}

	cout << (n + m - 2 + (n*m - 1)) << endl;
	fr(i, n-1){
		cout << 'U';
	}
	fr(i, m-1){
		cout << 'L';
	}
	fr(i, n){
		fr(j, m-1){
			if(i%2 == 0)cout << 'R';
			else cout << 'L';
		}
		if(i < n-1)cout << 'D';
	}
	cout << endl;
}
