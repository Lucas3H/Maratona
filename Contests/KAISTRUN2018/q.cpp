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
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 10010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100
#define P 1

ll p = MOD;
ll tam = 1;
stack<ll> s;
ll v[MAXN];
ll pwr27[MAXN];
ll pwr27_inv[MAXN];

ll get_hash(ll r, ll l){
	return ((v[r] - v[l-1] + p)*(pwr27_inv[l-1]))%p;
}

ll fastxp(ll n, ll e){
    if(e == 0) return 1;
    ll ans = fastxp(n, e/2);

    ans = (ans*ans)%p;

    if(e%2 == 1) ans *= n;

    return (ans)%p;
}

deque<ll> atual;
void add(char c){
	atual.pb(c - 'a' + 1);
	v[tam] = (v[tam-1] + pwr27[tam-1]*(c - 'a' + 1))%p;
	tam++;
}

void remove(){
	v[tam-1] = 0;

	tam--;
	s.pop();
	atual.pop_back();
}

void build(){
	pwr27[0] = 1;
	pwr27_inv[0] = 1;
		
	ll aux = fastxp(27, p - 2);;

	frr(j, MAXN-1){
		pwr27[j] = (pwr27[j-1]*27)%p;
		pwr27_inv[j] = (pwr27_inv[j-1]*aux)%p;
	}
}

int main(){
	ios::sync_with_stdio(false);

	build();
	s.push(0);

	ll q;
	cin >> q;
	string t;
	cin >> t;

	atual.pb(0);

	fr(x, q){
		if(t[x] == '-'){
			remove();
			cout << s.top() <<' ';
		}
		else{
			ll ans = s.top();
			add(t[x]);

			ll hash = 0, ind = 0;

			for(ll t_hash = 1; t_hash <= (tam+1)/2; t_hash++){
				hash = (hash + atual[tam-t_hash]*pwr27[ind])%p;
				if(hash == (get_hash(tam-t_hash, tam - t_hash - t_hash + 1))){
					ans++;
				}
				if(hash == (get_hash(tam - t_hash - 1, tam - t_hash - t_hash))){
					ans++;
				}	
				
				ind++;
			}

			s.push(ans);
			cout << ans << " ";
		}

		//cout << "\n-----------\n";
	}

	cout << endl;

}