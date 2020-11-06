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

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		int aux[4*MAXN];
		frm(i, n){
			cin >> aux[i];
		}
		vector<int> p;
		fr(i, n){
			p.pb(aux[i]);
		}

		int b_cf, s_cf, g_cf, b, s, g;

		if(n < 10) {
			cout << 0 << " " << 0 << " " << 0 << endl;
			continue;
		}

		b_cf = lower_bound(p.begin(), p.end(), p[(n-1)/2] + 1) - p.begin();
		g_cf = lower_bound(p.begin(), p.end(), p[n-1]) - p.begin();
		g = n - g_cf;

		s_cf = g_cf - g - 1;

		if(s_cf < 0){
			cout << "0 0 0\n";
			continue;
		}
		s_cf = lower_bound(p.begin(), p.end(), p[s_cf]) - p.begin();
		s = n - s_cf - g;
		 
		b = s_cf - b_cf;

		if(g > 0 && s > 0 && b > 0 && g < s && g < b){
			cout << g << " " << s << " " << b << endl;
		}
		else cout << "0 0 0" << endl;

	}
}
