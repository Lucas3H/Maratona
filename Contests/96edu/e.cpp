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

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100


ll vai[MAXN], recebe[MAXN];
string s;
ll n;
void build(char c){
	vector<ll> aux;
	fr(i, s.size()){
		if(s[i] == c){
			aux.pb(i + 1);
		}
	}

	fr(i, aux.size()){
		vai[aux[i]] = n + 1 - aux[aux.size() - 1 - i];
		recebe[n + 1 - aux[aux.size() - 1 - i]] = aux[i];
	}
}

ll nd[4*MAXN];
void update(ll i, ll l, ll r, ll pos){
	if(l == r){
		nd[i]++;
	}
	else{
		ll m = (l + r)/2;

		if(m >= pos) update(2*i, l, m, pos);
		else update(2*i+1, m + 1, r, pos);
		nd[i] = nd[2*i+1] + nd[2*i];
	}
}

ll query(ll i, ll l, ll r, ll ql, ll qr){
	if(ql <= l && r <= qr) return nd[i];
	else if(ql > r || l > qr) return 0;
	else{
		ll m = (l + r)/2;
		return query(2*i, l, m, ql, qr) + query(2*i+1, m+1, r, ql, qr);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;

	fr(i, 26) build('a' + i);

	ll ans = 0, voltando = 0;
/*
	frr(i, n){
		cout << vai[i] <<" ";
	}
	cout << endl;

	frr(i, n){
		cout << recebe[i] <<" ";
	}
	cout << endl;
*/
	for(ll i = n; i >= 1; i--){
		if(recebe[i] > i){
			voltando--;
		}

		//cout << ans << " " << voltando << " " << query(1, 1, n, i, vai[i]) << endl;
		if(vai[i] < i){
			voltando++;
			ans += query(1, 1, n, 1, vai[i]);
		}
		else{
			ans += voltando;
			ans += query(1, 1, n, i, vai[i]);
		}

		update(1, 1, n, vai[i]);
	}



	cout << ans << endl;
}
