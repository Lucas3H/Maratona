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

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		int n;
		int a[MAXN];
		vector<int> fr[2*MAXN];

		frr(i, n) {
			cin >> a[i];
			fr[a[i] + n].pb(i);
		}

		if(fr[n].size()> 0) {
			cout << 1 << endl;
			cout << fr[n][0] << endl;
			continue;
		}
		int deu = 0;

		frr(i, n){
			if(fr[i].size() > 0 && fr[i + n].size() != 0){
				cout << 2 << endl;
				cout << fr[i][0] << ' ' << fr[i+n][0] << endl;
				deu = 1;
			}
		}
		
		if(deu) continue;

		ll sum = 0;

		int ans = 0;
		frr(i, n){
			sum+=a[i];
			if(sum == 0){
				ans = i;
				break;
			}
		}

		cout << ans << endl;
		frr(i, ans) cout << i << " ";
		cout << endl;
	}
}
