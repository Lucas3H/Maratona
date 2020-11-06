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

#define yes cout << "Yes\n";
#define no cout << "No\n";

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int v[6];
		fr(i, 6) cin >> v[i];

		if(abs(v[2] - v[4]) == 0 && abs(v[3] - v[5]) == 0){
			if(a == 0 && b == 0 && c == 0 && d == 0){
				cout << "Yes\n";
			}
			else cout << "No\n";
		}
		else if(abs(v[2] - v[4]) == 0){
			if(a == 0 && b == 0){
				int pos = v[1] + d - c;
				if(v[3] <= pos && pos <= v[5]) cout << "Yes\n";
				else cout << "No\n";
			}
			else no
		}
		else if(abs(v[3] - v[5]) == 0){
			if(c== 0 && d == 0){
				int pos = v[0] + b - a;
				if(v[2] <= pos && pos <= v[4]) cout << "Yes\n";
				else cout << "No\n";
			}
			else no
		}
		else{
			int pos1 = v[0] + b - a;
			int pos2 = v[1] + d - c;

			if(v[2] <= pos1 && pos1 <= v[4] && v[3] <= pos2 && pos2 <= v[5]) yes
			else no
		}
	}
}
