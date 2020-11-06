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
typedef pair<ll, ll> ponto;
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

struct problem{
	ll dif, t;
};

ll n, T, a, b;
problem p[2*MAXN];

bool cmp(problem a, problem b){
	return a.t < b.t;
}

ll func(ll k, ll easy, ll hard){
	ll ans;
	if((ll)k/a <= easy) return (ll)k/a;
	else{
		k-=a*easy;
		return easy + min(hard, (ll)k/b);
	}
}

int main(){

	ll t;
	cin >> t;

	while(t--){
		scanf("%lld %lld %lld %lld", &n, &T, &a, &b);


		ll easy_total = 0, hard_total = 0;

		fr(i, n) {
			scanf("%lld", &p[i].dif);
			if(p[i].dif == 0) easy_total++;
			else hard_total++;
		}
		fr(i, n) scanf("%lld", &p[i].t);
		p[n].dif = 0;
		p[n].t = T + 1;

		sort(p, p+n + 1, cmp);

		ll total = 0, easy = 0, hard = 0, ans = 0;
		fr(i, n + 1){
			ll resto = p[i].t - 1 - total;

			if(resto >= 0) ans = max(ans, easy + hard + func(resto, easy_total - easy, hard_total - hard));
			//else break;

			if(p[i].dif == 0){
				easy++;
				total+=a;
			}
			else{
				hard++;
				total+=b;
			}

			//cout << ans << endl;
		}

		printf("%lld\n", ans);

	}	
}
