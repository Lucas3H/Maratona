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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

vector<char> ans;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	frr(ts, t){
		ll x, y;
		cin >> x >> y;

		cout << "Case #" << ts << ": ";

		if((x + y)%2 == 0){
			cout << "IMPOSSIBLE\n";
			continue;
		}
		
		ans.clear();
		while(x != 0 || y != 0){
			if(x == 0 && y == 1){
				ans.pb('N');
				break;
			}
			else if(x == 1 && y == 0){
				ans.pb('E');
				break;
			}
			else if(x == -1 && y == 0){
				ans.pb('W');
				break;
			}
			else if(x == 0 && y == -1){
				ans.pb('S');
				break;
			}

			if((y%2 + 2)%2 == 1){
				if(((y + x)%4 + 4)%4 == 1){
					ans.pb('S');
					y = (y + 1)/2;
				}
				else{
					ans.pb('N');
					y = (y - 1)/2;
				}

				x = x/2;
			}
			else{
				if(((y + x)%4 + 4)%4 == 1){
					ans.pb('W');
					x = (x + 1)/2;
				}
				else{
					ans.pb('E');
					x = (x - 1)/2;
				}
				y = y/2;
			}
		}
		for(auto x: ans) cout << x;
		cout << endl;
	}
}
