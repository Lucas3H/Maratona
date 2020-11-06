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

#define MAXN 1000010
#define MOD 1000000007

#define MAXL 30
#define ROOT 1
#define INF 987654321
#define MAXP 4

string s;
ll p[MAXP] = {MOD, MOD + 2, MOD + 30, 5761463};
ll power27[MAXP][MAXN];
ll hash_indo[MAXP][MAXN], hash_volta[MAXP][MAXN];

ll find(ll l, ll r, ll ini1, ll ini2){
	if(ini1 == ini2){
		if(2*ini1 < (l+r)){
			ll deu = 1;
			ll tam = (ini1 - l);
			ll pw = r - ini2 - tam;

			fr(h, 3){
				if((hash_indo[h][ini1]*power27[h][pw])%p[h] != (hash_volta[h][ini1] - hash_volta[h][ini1+tam + 1] + p[h])%p[h])deu = 0;
			}

			if(deu) return 2*tam + 1;
			else return -1;
		}
		else{

			ll deu = 1;
			ll tam = (r - ini2);
			ll pw = ini1 - tam - l;

			if(ini1 - tam == 0){
				fr(h, 3){
					if((hash_volta[h][ini2]*power27[h][pw])%p[h] != (hash_indo[h][ini1] + p[h])%p[h]) deu = 0;
				}	
			}
			else{
				
				fr(h, 3){
					if((hash_volta[h][ini2]*power27[h][pw])%p[h] != (hash_indo[h][ini1] - hash_indo[h][ini1-tam - 1] + p[h])%p[h]) deu = 0;
				}

			}

			if(deu) return 2*tam + 1;
			else return - 1;
		}
	}
	else{
		if(2*ini1 < l + r){
			ll deu = 1;
			ll tam = (ini1 - l);
			ll pw = r - ini2 - tam;

			fr(h, 3){
				if((hash_indo[h][ini1]*power27[h][pw])%p[h] != (hash_volta[h][ini2] - hash_volta[h][ini2+tam + 1] + p[h])%p[h])deu = 0;
			}

			if(deu) return 2*tam + 2;
			else return -1;
		}
		else{
			ll deu = 1;
			ll tam = (r - ini2);
			ll pw = ini1 - tam - l;

			if(ini1 - tam == 0){

				fr(h, 3){
					if((hash_volta[h][ini2]*power27[h][pw])%p[h] != (hash_indo[h][ini1] + p[h])%p[h]) deu = 0;
				}

			}
			else{
				fr(h, 3){
					if((hash_volta[h][ini2]*power27[h][pw])%p[h] != (hash_indo[h][ini1] - hash_indo[h][ini1-tam - 1] + p[h])%p[h]) deu = 0;
				}
			}


			if(deu) return 2*tam + 2;
			else return -1;
		}
	}
}

void prll(ll l, ll r, ll ans, ll side){
	fr(i, l){
		cout << s[i];
	}

	if(side == 0){
		for(ll i = l; i <= l + ans - 1;i++){
			cout << s[i];
		}
	}
	else{
		for(ll i = r - ans + 1; i <= r; i++){
			cout << s[i];
		}
	}

	for(ll i = r + 1; i < s.size(); i++){
		cout << s[i];
	}

	cout << endl;
}

void build_hash(ll l, ll r){
	fr(h, 3){
		fr(i, s.size()){
			hash_indo[h][i] = 0;
			hash_volta[h][i] = 0;
		}
	}
	fr(h, 3){
		ll power = 1;
		ll ant = 0;
		for(ll i = l; i <= r; i++){
			hash_indo[h][i] = ((s[i] - 'a' + 1)*power + ant)%p[h];
			ant = hash_indo[h][i];
			power = (power*27)%p[h];
		}

		ant = 0;
		power = 1;
		for(ll i = r; i >= l; i--){
			hash_volta[h][i] = ((s[i] - 'a' + 1)*power + ant)%p[h];
			ant = hash_volta[h][i];
			power = (power*27)%p[h];
		}
	}
}

ll ftxp(ll b, ll e, ll ind){
	if(e == 0) return 1;
	else{
		ll ans = ftxp(b, e/2, ind);
		ans = (ans*ans)%p[ind];

		if(e%2 == 1) ans = (ans*b)%p[ind];

		return ans;
	}
}

void build_pow(){
	fr(h, 3){
		power27[h][0] = 1;
		frr(i, MAXN - 1){
			power27[h][i] = (power27[h][i-1]*27)%p[h];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;

	build_pow();

	while(t--){
		cin >> s;

		ll l = 0, r = s.size() - 1;

		while(s[l] == s[r] && l < r){
			l++;
			r--;
		}


		if(l == r){
			cout << s<< endl;
			continue;
		}

		build_hash(l, r);

		ll side = -1, mid = (l + r)/2, ans= 0;

		for(ll i = l; i <= r; i++){
			ll val = find(l, r, i, i);

			if(val > ans){
				ans = val;
				if(2*i < l + r) side = 0;
				else side = 1;
			}
		}

		for(ll i = l; i < r; i++){
			ll val = find(l, r, i, i+1);

			if(val > ans){
				ans = val;
				if(2*i < l + r) side = 0;
				else side = 1;
			}
		}
/*
		cout << l << " " << r << " " << ans << endl;

		fr(i, s.size()){
			cout << hash_indo[0][i] << ' ';
		}
		cout << endl;
		frm(i, s.size()){
			cout << hash_volta[0][i] << ' ';
		}
*/

		prll(l, r, ans, side);
	}
}
