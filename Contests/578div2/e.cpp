// 
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
#define MAXP 3
#define MOD 1000000007
#define ROOT 1
#define INF 98765421

ll p[MAXP] = {196613, 393241, 786433};
ll dez[MAXP][MAXN];

ll getvalue(char c){
	if(c >= 'a' && c <= 'z'){
		return c - 'a' + 1;
	}

	if(c >= 'A' && c <= 'Z'){
		return c - 'A' + 27;
	}

	return c - '0' + 53;
}

char resp[MAXN];
int s[MAXP][MAXN];

ll val[MAXP];
int tam = 0;

ll best(string a, string b){
	ll hash[MAXP] = {0, 0, 0};
	frm(i, a.size()){
		fr(j, MAXP){
			hash[j] = (62*hash[j])%p[j];
			hash[j] = (hash[j] + getvalue(a[i]))%p[j];
		}
	}

	fr(j, MAXP){
		cout << hash[j] << " ";
	}
	cout << endl;

	fr(j, MAXP){
		val[j] = (val[j] + hash[j])%p[j];		
	}

	fr(j, MAXP){
		hash[j] = 0;
 	}

	frm(i, a.size()){
		fr(j, MAXP){
			hash[j] = (63*hash[j])%p[j];
			hash[j] = (hash[j] + getvalue(a[i]))%p[j];
			s[j][(hash[j] - val[j] + p[j])%p[j]] = 1;
			cout << j << " " << (hash[j] - val[j] + p[j])%p[j] << endl;
		}
	}

	fr(j, MAXP){
		hash[j] = 0;
 	}

	ll ans = 0;
	fr(i, b.size() + 1){
		ll deu = 1;
		fr(j, MAXP){
			if(s[j][(hash[j] - val[j] + p[j])%p[j]] == 0){
				deu = 0;
				break;
			}
		}

		if(deu) ans = i;

		if(i == b.size()) break;

		fr(j, MAXP){
			hash[j] = (hash[j] + dez[j][i]*getvalue(b[i]))%p[j];
		}
	}

	cout << ans << endl;
	return ans;
}

int main(){
	fr(i, MAXP){
		dez[i][0] = 1;
		frr(j, MAXN - 1){
			dez[i][j] = (63*dez[i][j-1])%p[i];
		}
	}

	ll n;
	cin >> n;

	string s, p;
	cin >> s;
	cout << s;
	fr(i, n-1){
		cin >> p;
		ll l = best(s, p);
		//cout << l << endl;
		for(ll j = l; j < p.size(); j++){
			printf("%c", p[j]);
		}
		s = p;
	}

	cout << endl;
}
