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

ll n, k;
ll v[MAXN];
map<ll, ll> m;
class BIT{
    public:
        ll v[MAXN], bit[MAXN];
        ll n;

        void update(ll i, ll val){
            while(i <= n){
                bit[i] += val;
                i += i & (-i);
            }
        }

        ll query(ll i){
            ll sum = 0;

            while(i > 0){
                sum += bit[i];
                i -= i & (-i);
            }

            return sum;
        }

        ll queryInt(ll l, ll r){
        	return query(r) - query(l-1);
        }

        void clear(){
        	mem(bit, 0);
        }

};

BIT par, impar, n_par, n_impar;

ll tot;

void read(){
	set<ll> aux;
	cin >> n >> k;
	frr(i, n) {
		cin >> v[i];
		aux.insert(v[i]);
	}

	ll ind = 1;
	for(ll x: aux){
		m[x] = ind++;
	}

	par.n = ind;
	impar.n = ind;
	n_par.n = ind;
	n_impar.n = ind;
	tot = ind;
}

ll ans = 0;

ll solvePos(ll ind, ll tipo){

	ll ret = 0;
	if(k%2 == 1){
		if(ind%2 == 0){
			ret += v[ind]*n_par.query(m[v[ind]]) - par.query(m[v[ind]]);
			ret += par.queryInt(m[v[ind]], tot) - v[ind]*n_par.queryInt(m[v[ind]], tot);

			if(ind - k + 1 > 0 && tipo){
				par.update(m[v[ind - k + 1]], -v[ind - k + 1]);
				n_par.update(m[v[ind - k + 1]], -1);
			}	

			if(tipo == 1){
				par.update(m[v[ind]], v[ind]);
				n_par.update(m[v[ind]], 1);
			}
		}
		else{
			ret += v[ind]*n_impar.query(m[v[ind]]) - impar.query(m[v[ind]]);
			ret += impar.queryInt(m[v[ind]], tot) - v[ind]*n_impar.queryInt(m[v[ind]], tot);
			
			if(ind - k + 1 > 0 && tipo){
				impar.update(m[v[ind - k + 1]], -v[ind - k + 1]);
				n_impar.update(m[v[ind - k + 1]], -1);
			}

			if(tipo == 1){
				impar.update(m[v[ind]], v[ind]);
				n_impar.update(m[v[ind]], 1);
			}
		}
	}
	else{
		if(ind%2 == 1){
			ret += v[ind]*n_par.query(m[v[ind]]) - par.query(m[v[ind]]);
			ret += par.queryInt(m[v[ind]], tot) - v[ind]*n_par.queryInt(m[v[ind]], tot);

			if(ind - k + 1 > 0 && tipo){
				par.update(m[v[ind - k + 1]], -v[ind - k + 1]);
				n_par.update(m[v[ind - k + 1]], -1);
			}	

			if(tipo == 1){
				impar.update(m[v[ind]], v[ind]);
				n_impar.update(m[v[ind]], 1);
			}
		}
		else{

			ret += v[ind]*n_impar.query(m[v[ind]]) - impar.query(m[v[ind]]);
			ret += impar.queryInt(m[v[ind]], tot) - v[ind]*n_impar.queryInt(m[v[ind]], tot);
		
			if(ind - k + 1 > 0 && tipo){
				impar.update(m[v[ind - k + 1]], -v[ind - k + 1]);
				n_impar.update(m[v[ind - k + 1]], -1);
			}

			if(tipo == 1){
				par.update(m[v[ind]], v[ind]);
				n_par.update(m[v[ind]], 1);
			}
		}
	}

	return ret;
}

void solve(){
	for(ll i = 1; i <= n;i++){
		//cout << impar.query(3) << endl;
		ans += solvePos(i, 1);
	}
}

void computeTirar(){
	par.clear();
	n_par.clear();
	impar.clear();
	n_impar.clear();

	for(ll i = 1; i <= k-1; i++){
		if(i%2 == 0){
			par.update(m[v[i]], v[i]);
			n_par.update(m[v[i]], 1);
		}
		else{
			impar.update(m[v[i]], v[i]);
			n_impar.update(m[v[i]], 1);
		}
	}

	for(ll i = 1; i <= k/2; i++){
		if(i%2 == 0){
			par.update(m[v[i]], -v[i]);
			n_par.update(m[v[i]], -1);
		}
		else{
			impar.update(m[v[i]], -v[i]);
			n_impar.update(m[v[i]], -1);
		}

		ans -= solvePos(i, 0);
		if((k - i)%2 == 0){
			par.update(m[v[k-i]], -v[k-i]);
			n_par.update(m[v[k-i]], -1);
		}
		else{
			impar.update(m[v[k-i]], -v[k-i]);
			n_impar.update(m[v[k-i]], -1);
		}
	}

	par.clear();
	n_par.clear();
	impar.clear();
	n_impar.clear();

	for(ll i = n; i >= n - k + 2; i--){
		if(i%2 == 0){
			par.update(m[v[i]], v[i]);
			n_par.update(m[v[i]], 1);
		}
		else{
			impar.update(m[v[i]], v[i]);
			n_impar.update(m[v[i]], 1);
		}
	}

	for(ll i = n; i >= n - k/2 + 1; i--){
		if(i%2 == 0){
			par.update(m[v[i]], -v[i]);
			n_par.update(m[v[i]], -1);
		}
		else{
			impar.update(m[v[i]], -v[i]);
			n_impar.update(m[v[i]], -1);
		}

		ans -= solvePos(i, 0);

		//cout << m[v[k - (n + 1 - i)]] << " " << k - (n + 1 - i) << endl;

		if((i - k + 2)%2 == 0){
			par.update(m[v[i - k + 2]], -v[i - k + 2]);
			n_par.update(m[v[i - k + 2]], -1);
		}
		else{
			impar.update(m[v[i - k + 2]], -v[i - k + 2]);
			n_impar.update(m[v[i - k + 2]], -1);
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	read();
	solve();
	computeTirar();
	cout << ans << endl;
}
