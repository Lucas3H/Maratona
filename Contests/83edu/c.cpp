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

ll k;

vector<ll> dec(ll n){
	vector<ll> ret;

	while(n > 0){
		ret.pb(n%k);
		n/=k;
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n >> k;

		vector<ll> dig[50];
		fr(i, n){
			ll x;
			cin >> x;
			dig[i] = dec(x);
		}

		ll used[MAXN];
		fr(i, 1000) used[i] = 0;

		int deu = 1;

		fr(i, n){
			fr(j, dig[i].size()){
				if(dig[i][j] > 1){
					deu = 0;
					break;
				}
				else if(dig[i][j] == 1) used[j]++;
			}
		}

			fr(i, 1000){
				if(used[i] > 1){
					deu = 0;
					break;
				}
			}

		if(deu == 0){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
}
