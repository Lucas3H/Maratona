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

int main(){
	ios::sync_with_stdio(false);
	int t, b;
	cin >> t >> b;
	frr(ts, t){
		int inv = 0, comp = 0;
		set<int> eq[2];
		set<int> dif[2]; /**/

		int ans[110], x, it = 1, qs = 1, y;

		while(it <= (b + 1)/2 && qs < 150){
			if(qs%10 == 1){
				cout << it << endl;
				cin >> x;
				qs++;

				if(it == 1) continue;
				else if(inv && comp){
					
				}
			}
			else{
				cout << it << endl;
				cin >> x;

				if(inv && comp) ans[n + 1 - it] = 1 - x;
				else if(inv && !comp) ans[n + 1 - it] = x;
				else if(!inv && comp) ans[it] = 1 - x;
				else ans[it] = x;

				cout << n + 1 - it << endl;
				cin >> x;

				if(inv && comp) ans[it] = 1 - x;
				else if(inv && !comp) ans[it] = x;
				else if(!inv && comp) ans[n + 1 - it] = 1 - x;
				else ans[n + 1 - it] = x;

				if(ans[n + 1 - it] == ans[it]){
					eq[ans[it]].insert(it);
				}
				else{
					df[ans[it]].insert(it);
				}

				it++;

				qs+=2;
			}
		}
	}
}
