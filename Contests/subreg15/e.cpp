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
	ll n, b;
	cin >> n >> b;

	if(n%2 == 1){
		if(b == n*n){
			cout << (n+1)/2 <<  " " << (n+1)/2 << endl;
			return 0;
		}
		
		ll l = 0, r = (n-1)/2, m;
		
		while(l < r - 1){
			m = (l + r)/2;

			if(b > 4*m*(n - m)){
				l = m;
			}
			else r = m;
		}

		m = l;
		
		b -= 4*m*(n - m);
		l = (n - 2*m);

		if(b <= (l-1)){
			cout << m + 1 << " " << m + b << endl;
			return 0;
		}
		
		b -= (l-1);

		if(b <= (l-1)){
			cout << m + b << " " << n - m << endl;
			return 0;
		}

		b -= (l-1);

		if(b <= (l-1)){
			cout << n - m << " " << n - m - b + 1 << endl;
			return 0;
		}

		b -= (l-1);

		cout << n - m - b + 1 << " " << m + 1 << endl;
	}
	else{		
		ll l = 0, r = n/2 + 1, m;
		
		while(l < r - 1){
			m = (l + r)/2;

			if(b > 4*m*(n - m)){
				l = m;
			}
			else r = m;
		}

		m = l;

		b -= 4*m*(n - m);
		l = (n - 2*m);

		if(b <= (l-1)){
			cout << m + 1 << " " << m + b << endl;
			return 0;
		}
		
		b -= (l-1);

		if(b <= (l-1)){
			cout << m + b << " " << n - m << endl;
			return 0;
		}

		b -= (l-1);

		if(b <= (l-1)){
			cout << n - m << " " << n - m - b + 1 << endl;
			return 0;
		}

		b -= (l-1);

		cout << n - m - b + 1 << " " << m + 1 << endl;
	
	}
}
