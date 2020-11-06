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

bool zero(ll k){
	while(k > 0){
		if(k%10 == 0) return 1;

		k/=10;
	}

	return 0;
}

ll sum(ll k){
	ll menor = 9, maior = 0;

	while(k > 0){
		menor = min(menor, k%10);
		maior = max(maior, k%10);

		k/=10;
	}

	return maior*menor;
}

ll solve(ll a, ll k){
	while(k > 0 && !zero(a)){
		k--;
		a+=sum(a);
	}

	return a;
}

int main(){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;

	while(t--){
		ll a, k;
		cin >> a >> k;

		cout << solve(a, k-1) << endl;
	}
}
