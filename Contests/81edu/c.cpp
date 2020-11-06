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

	int t;
	cin >> t;

	while(t--){
		string s, t;
		cin >> s >> t;

		vector<int> a[30];

		fr(i, s.size()){
			a[s[i] - 'a'].pb(i);
		}

		int pos_davez = -1, ans = 1, deu = 1;
		
		fr(i, t.size()){
			if(a[t[i] - 'a'].size() == 0){
				deu = 0;
				break;
			}

			//cout << pos_davez << " " ;

			auto x = lower_bound(a[t[i] - 'a'].begin(), a[t[i] - 'a'].end(), pos_davez + 1);
		
			if(x == a[t[i] - 'a'].end()){
				ans++;
				pos_davez = a[t[i] - 'a'][0];
			}
			else{
				pos_davez = (*x);
			}
		}
		//cout << endl;

		if(deu) cout << ans << endl;
		else cout << -1 << endl;
	}
}
