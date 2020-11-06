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
typedef pair<int, int> ponto;
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

int m[710][710];
int val[500010];

int main(){
	ios::sync_with_stdio(false);
	int q;
	cin >> q;

	while(q--){
		int t, x, y;
		cin >> t >> x >> y;

		if(t == 1){
			val[x]+=y;
			frr(i, 705){
				m[i][x%i]+=y;
			}
		}
		else{
			if(x <= 705) cout << m[x][y] << endl;
			else{
				int ans = 0;
				int it = y;
				while(it <= 500000){
					ans+=val[it];
					it+=x;
				}

				cout << ans << endl;
			}
		}
	}
}
