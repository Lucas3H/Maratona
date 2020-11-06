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

int main(){
	ios::sync_with_stdio(false);

	//freopen("scoreboard.in", "r", stdin);

	int t;
	cin >> t;

	while(t--){
		int k;
		cin >> k;
		string s;
		cin >> s;

		int m[20];
		fr(i, 13) m[i] = 0;		
		fr(i, k) m[s[i] - 'A'] = 1;

		pii pt[20];

		fr(i, 13) cin >> pt[i].f, pt[i].s = i;
		sort(pt, pt + 13);

		int ans = -1;
		frm(i, 13){
			//cout << pt[i].f << " " << pt[i].s << endl;
			if(m[pt[i].s] == 0){
				ans = pt[i].s;
				break;
			}
		}

		cout << (char)(ans + 'A') << endl;
	}
}
