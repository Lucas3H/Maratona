#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
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
		ll n;
		cin >> n;

		ll d = 0;

	//	cout << d << endl;
		int v[11];

		ll last;
		ll deu = 1;
		ll k = n;

		while(n > 0){
			last = n%10;
			n/=10;
			v[d] = last;
			d++;
		}

		ll ans = 9*(d-1);

		frm(i, d){
			if(v[i] > last) break;
			if(v[i] < last){
				deu = 0;
				break;
			}
		}

		if(deu) ans++;

		ans += (last-1);

		cout << ans << endl;
	}
}
