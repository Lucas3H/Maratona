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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll pot2[100];
ll maxl = 0;

vector<ll> a;

ll n, m, sum;
ll tenho[100];

void read(){
	cin >> n >> m;

	sum = 0;
	a.clear();
	fr(i, m){
		ll ax;
		cin >> ax;
		a.pb(ax);

		sum+=ax;
	}

	fr(i, 100) pot2[i] = 0;
	fr(i, 100) tenho[i] = 0;

	fr(i, m) {
		ll l = (ll)floor((log(a[i]) + 0.00000000001)/log(2));

		tenho[l]++;
	}
}

int main(){
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	while(t--){
		read();

		maxl = 0;
		while(n > 0){
			if(n%2 == 1) pot2[maxl] = 1;

			n/=2;
			maxl++;
		}

		ll ans = 0;

		ll prox[100];
		ll ultimo = 100;
		frm(i, 100){
			prox[i] = ultimo;

			if(tenho[i] > 0) ultimo = i;
		}
/*
		fr(i, maxl) cout << pot2[i] << " ";
		cout << endl;
*/
		ll deu = 0;

		fr(i, maxl){
			if(pot2[i] == 1){
				if(tenho[i] == 0){

					if(prox[i] == 100) {
						deu = 1;
						break;
					}

					tenho[prox[i]]--;

					ans += prox[i] - i;
					i = prox[i] - 1;
				}
				else{
					//cout << "okas " << i << " " << tenho[i] << " ";
					tenho[i]--;
					//cout << tenho[i] << endl;
				}
			}

		//	cout << i << endl;
/*			fr(j, maxl) cout << tenho[j] << " ";
			cout << endl;
*/
			tenho[i+1] += (tenho[i])/2;	
/*
			fr(j, maxl) cout << tenho[j] << " ";
			cout << endl;
*/		}

		if(deu) cout << -1 << endl;
		else cout << ans << endl;
	}
}
