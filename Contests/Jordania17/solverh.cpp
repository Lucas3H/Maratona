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
typedef pair<ll, ll> pll;
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
#define INF 1000000000000000100


int solve(string s){
	//cout << s << endl;
	int n = s.size();
	int ret = n;
	for(int i = 0; i < n; i++){
		if(s[i] == '+') continue;
		s[i] = '+';

		int ans[100];
		fr(j, n) ans[j] = n;

		int acu = n;
		fr(j, n){
			if(s[j] == '+'){
				acu = 1;
				ans[j] = 0;
				continue;
			}

			ans[j] = min(ans[j], acu);
			acu++;
		}

		acu = n;
		frm(j, n){
			if(s[j] == '+') {
				acu = 1;
				ans[j] = 0;
				continue;
			}

			ans[j] = min(ans[j], acu);
			acu++;
		}

		int maior = 0;
		fr(j, n) maior = max(maior, ans[j]);
		ret = min(ret, maior);

		
		s[i] = '.';
		/*
		cout << s << endl;
		fr(j, n) cout << ans[j] <<" ";
		cout << endl;
		*/
	}

	return ret;
}
int n;
int main(){
	ios::sync_with_stdio(false);

	//cout << solve("...+..++..") << endl;

	int t;
	string s;
	cin >> t;

	while(t--){
		cin >> n;
		cin >> s;
		
		vector<int> gas;
	
		fr(i, s.size()){
			if(s[i] == '+') gas.pb(i + 1);
		}
	
		int ans = n;

		for(int i = 0; i < n; i++){
			if(s[i] == '.') continue;

			s[i] = '.';
			//cout << solve(s) << " " << s << endl;
			ans = min(solve(s), ans);
			s[i] = '+';
		}

		cout << ans << endl;
	}

}
