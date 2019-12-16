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

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		vector<pii> zeros;
		string s;
		cin >> s;

		int i = 0;
		ll ans = 0;
		while(i < s.size()){
			if(s[i] == '1') {
				ans++;
				i++;
			}
			else{
				int ini = i;
				while(s[i] == '0' && (i < s.size())){
					i++;
				}
				zeros.pb(mp(ini, i-1));
			}
		}

		fr(i, s.size() - 1){
			if(s[i] == '1' && s[i+1] == '0') ans++;
		}

		fr(i, zeros.size()){
			int digits = zeros[i].s - zeros[i].f+1;
			int j = zeros[i].s + 1;
			int num = 0;

			while(num <= digits && j < s.size()){
				if(num >= 3) {
					ans++;
				}

				digits++;
				num*=2;
				num += (s[j] - '0');
				j++;
			}

			if(num <= digits && num >= 3) ans++;
		}

		cout << ans << endl;
	}
}
