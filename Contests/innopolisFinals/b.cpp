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

ll fr[110];
vector<vector<ll>> pos[110];
ll n;
ll sum_tot = 0;
ll cem = (ll)100;

void build(ll val){
	vector< pair<ll, ll> > novo;

	frr(i, cem - 1){
		if(pos[i].size() > 0){
			vector<ll> aux;

			ll maximo = min((cem - i)/val, fr[val]);

			for(ll j = 1; j <= maximo; j++){
				fr(k, pos[i].size()){
					novo.pb(mp(j*val + i, i));
/*
					aux = pos[i][k];
			
*/				}
			}
		}
	}

	for(auto x: novo){
		fr(i, pos[x.s].size()){
			vector<ll> aux = pos[x.s][i];
			aux.pb(val);

			pos[x.f].pb(aux);
		}
	}

	ll maximo = min((cem)/val, fr[val]);

	for(ll j = 1; j <= maximo; j++){
		vector<ll> aux;
		aux.pb(val);

		pos[j*val].pb(aux);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;

	fr(i, n){
		ll x;
		cin >> x;
		sum_tot += x;

		if(x <= cem) fr[x]++;
	}

	frr(i, cem - 1) build(i);

	set<ll> ans;

	fr(i, cem){
		if(pos[i].size() == 0) continue;
		
		ll num = cem*(sum_tot - i);
		ll mod = cem - i;

		if(num == 0) continue;

		if(num%(mod) == 0){
			ll t = num/(mod);
			
			int add = 0;

			//cout <<"cal " <<  i << endl;

			fr(k, pos[i].size()){
				int deu = 1;
				for(auto x: pos[i][k]){
					if((t*x)%cem != 0){
						deu = 0;
						break;
					}

					//cout << x<< ' ';
				}

				//cout << endl;

				if(deu) {
					add = 1;
					break;
				}
			}

			if(add){
				//cout << t << " adsa ddasaasd\n";
				ans.insert(t);
			}
		}
	}

	ans.insert(sum_tot);

	cout << ans.size()<< endl;
	for(auto x: ans) cout << x<< " ";
	cout << endl;
}
 