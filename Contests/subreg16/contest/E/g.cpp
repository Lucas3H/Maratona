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

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

ll n;
string xn;
ll s[MAXN];
string num[100];
int val[100][10];
ll fat[200];

map<char, ll> m;
char inv[30];

ll stal(string a){
	ll ret = 0, seis = 1;
	for(int i = a.size() - 1; i >= 0; i--){
		ret += seis*m[a[i]];
		seis *= 16;
	}

	return ret;
}

ll retira(ll mask, int ind, int tam){
	ll l = 0, ret = 0, dezeseis = 1;
	ll v[10];

	frm(i, tam){
		if((mask & (1 << val[ind][i])) == 0){
			ret += dezeseis*val[ind][i];
			l++;
			dezeseis *= 16;
		}
	}

	if(l == 0) return 0;
	return ret;
}

ll get_sum(ll mask){
	ll ret = 0;
	fr(i, n){
		ret += retira(mask, i, num[i].size());
	}

	return ret;
}

void build_s(){
	fr(i, (1 << 16)){
		s[i] = get_sum(i);
	}
}

void init(){
	fr(i, 10) m[(char)(i + '0')] = i, inv[i] = (char)(i + '0');
	fr(i, 6) m[(char)(i + 'a')] = 10 + i, inv[i + 10] = (char)(i + 'a');
	fat[0] = 1;

	frr(i, 18) fat[i] = i*fat[i-1];

	cin >> xn;
	n = stoll(xn, 0, 16);
	fr(i, n) {
		cin >> num[i];
		fr(j, num[i].size()){
			val[i][j] = m[num[i][j]];
		}
	}
}

string get_hex(ll a){
	//cout << a << endl;
	if(a == 0) return "0";
	string ret = "";
	while(a > 0){
		ll r = a%16;

		ret = inv[r] + ret;

		a /= 16;
	}

	return ret;
}

ll maximo[MAXN], minimo[MAXN];

void solve(){
	maximo[(1 << 16) - 1] = 0;
	for(ll mask = (1 << 16) - 1; mask >= 0; mask--){
		for(ll j = 0; j < 16; j++){
			if((mask & (1 << j)) == 0){
				maximo[mask] = max(maximo[mask], maximo[(mask | (1 << j))] + s[mask]);
			}	
		}
	}

	fr(i, (1 << 16)) minimo[i] = INF;
	minimo[(1 << 16) - 1] = 0;
	for(ll mask = (1 << 16) - 1; mask >= 0; mask--){
		for(ll j = 0; j < 16; j++){
			if((mask & (1 << j)) == 0){
				minimo[mask] = min(minimo[mask], minimo[(mask | (1 << j))] + s[mask]);
			}	
		}
	}

	cout << get_hex(minimo[0] - s[0]) << " ";
	cout << get_hex(maximo[0] - s[0]) << " ";
}

int main(){
	ios::sync_with_stdio(false);
	init();
	build_s();

	ll tot = 0, l = 0;
	frr(i, (1 << 16) - 1){

		ll d = __builtin_popcount(i);
		ll termo = (s[i])%MOD;
		ll f1 = (fat[d])%MOD, f2 = (fat[16 - d])%MOD;
		
		termo = (termo*f1)%MOD;
		termo = (termo*f2)%MOD;

		//if(s[i] > 0) l++;
		tot = (termo + tot)%MOD;
	}

	solve();
	cout << get_hex(tot) <<endl;

}
