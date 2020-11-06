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

#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n, d;
pair<pii, int> p[MAXN];

bool comp(pair<pii, int> a, pair<pii, int> b){
	return a.f.s > b.f.s;
}

void read(){
	cin >> n >> d;
	frr(i, n){
		cin >> p[i].f.f >> p[i].f.s >> p[i].s; 
	}

	sort(p + 1, p + n + 1, comp);
}

int ans;
const int maxi = 1e8 + 1;
int dp[maxi];

int main(){
	ios::sync_with_stdio(false);

	read();

	frr(i, n){
		int deu = 0;
		
		//cout << p[i].f.s << " carai" << endl;
		fr(j, p[i].f.s){
			if(p[i].f.s + j < maxi){
				if(dp[p[i].f.s + j] + p[i].f.f > d){
					deu = 1;
				}

				dp[j] = max(dp[j], min(dp[p[i].f.s + j] + p[i].s, maxi));
			}
			else break;
		}

		if(deu) ans++;
	}
	/*
	frr(i, 20){
		cout << dp[i] << endl;
	}
	*/

	cout << ans << endl;
}
