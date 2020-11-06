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
#define INF 987654321

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main(){
	ios::sync_with_stdio(false);

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll C = sqrt(c);

	vector<ll> deu;

	for(ll q = 1; q <= C; q++){
		if(c%q == 0){
			if(q%a == 0 && q%b != 0 && d%q != 0){
				cout << q << endl;
				return 0;
			}

			ll oto = c/q;

			if(oto%a == 0 && oto%b != 0 && d%oto != 0){
				deu.pb(oto);
			}	
		}
	}

	if(deu.empty()) cout << -1  << endl;
	else cout << deu.back() << endl;
	return 0;
}
