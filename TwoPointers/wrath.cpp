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

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int main(){
	ios::sync_with_stdio(false);

	int n;
	int claw_range[MAXN];

	cin >> n;

	frr(i, n){
		cin >> claw_range[i];
	}

	int p1 = n, p2 = n + 1;
	int alive = 0;

	while(p1 > 0){
		if(p1 < p2){
			alive++;
		}

		p2 = min(p2, p1 - claw_range[p1]);
		p1--;

		//cout << p1 << ' ' << p2 << endl;
	}

	cout << alive << endl;
}
