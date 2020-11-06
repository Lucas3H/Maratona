#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
		ios::sync_with_stdio(false);
		int n, q;
		cin >> n >> q;

		int a[MAXN];

		deque<int> k;
		fr(i, n){
				cin >> a[i];
				k.pb(a[i]);
		}

		int m = 0;
		fr(i, n){
				if(a[i] > a[m]) m = i;
		}

		pii resp[3*MAXN];

		fr(i, m){
				int x = k.front();
				k.pop_front();
				int y = k.front();
				k.pop_front();

				if(x > y){
						resp[i] = mp(x, y);
						k.push_back(y);
						k.push_front(x);
				}
				else{
						resp[i] = mp(x, y);
						k.push_back(x);
						k.push_front(y);
				}
		}

		while(q--){
				ll c;
				cin >> c;

				if(c <= (ll)m) cout << resp[c-1].first << " " << resp[c-1].second << endl;
				else{
						ll r = (c - (ll)m - 1)%(n-1);

						cout << a[m] << " " << k[r + 1] << endl;
				}
		}
}
