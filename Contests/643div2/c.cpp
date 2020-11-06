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

ll a, b, c, d;

ll getSum(ll l, ll r){
	return r*(r+1)/2 - l*(l-1)/2;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> a >> b >> c >> d;

	ll ans = 0;

	for(ll i = a; i <= b; i++){
		if(d - i + 1 >= c){
			ans+=getSum(max(c-i + 1, b) + i - c, i);
		}
		else if(d - i + 1 < b){
			ans += (c - b + 1)*(d - c + 1);
		}
		else{
			ans+=getSum(max(c-i + 1, b) + i - c,d - c + 1) + (c - (d - i + 1))*(d - c + 1);
		}
	}

	cout << ans << endl;
}
