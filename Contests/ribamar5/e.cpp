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

const ll N = 10000000;
ll lp[N+1];
vector<ll> pr;

void crivo(){
	for (ll i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (ll j=0; j<(ll)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}
ll times[2];

ll read(ll ind){
	double a;
	cin >> a;

	ll ia = (ll)floor(a);
	times[ind] = 0;
	while(abs((double)ia - a) > 0.000001 && times[ind] < 10){
		a*=(double)10;
		ia = (ll)floor(a + 0.000001);
		times[ind]++;
	}

	return ia;
}

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main(){
	crivo();

	ll n;
	cin >> n;

	while(n--){
		ll a = read(0), b = read(1);

		if(times[0] > times[1]){
			b *= pow(10, times[0] - times[1]);
		}
		else{
			a *= pow(10, times[1] - times[0]);		
		}

		//cout << a << ' ' << b << endl;

		ll d = gcd(a, b);
		
		a/=d;
		b/=d;

		if(a == b){
			printf("2 2\n");	
		}
		else if(lp[a] == a && lp[b] == b){
			printf("%lld %lld\n", a, b);
		}
		else{
			printf("impossible\n");
		}
	}
}
