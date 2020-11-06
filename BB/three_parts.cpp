// 
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int main(){
	ios::sync_with_stdio(false);

	ll v[MAXN];
	ll n;
	cin >> n;

	frr(i, n) cin >> v[i];

	ll p1 = 0, p3 = n+1, sum1 = 0, sum3 = 0, ans = 0;

	while(p1 < p3){
		if(sum1 == sum3) 
			ans = max(ans, sum1);

		if(sum1 > sum3){
			p3--;
			sum3 += v[p3];
		}
		else{
			p1++;
			sum1 += v[p1];
		}
	}

	cout << ans << endl;
}
