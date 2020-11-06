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

#define MAXN 400010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll n;
ll a[MAXN];
ll ans = 0;

void solve(ll d){
	ll aux[MAXN];
	fr(i, n){
		aux[i] = a[i]%(1 << (d+1));
	}

	sort(aux, aux + n);

	ll p1 = 0, p2 = n-1, p3 = n-1, p4 = n-1;
	ll tot = 0;

	ll lim2 = (1 << (d + 1 )) + (1 << d);

	while(p1 < n - 1){
		if(aux[p1] + aux[p2] >= lim2 && p2 > p1) p2--;
		else if(aux[p1] + aux[p4] >= (1 << d) && p4 > p1) p4--;
		else if(aux[p1] + aux[p3] >= (1 << (d + 1)) && p3 > p1) p3--;
		else{
			tot += (n - 1 - p2);
			tot += max(p3 - p4, (ll)0);
			p1++;
			if(p2 < p1) p2++;
			if(p3 < p1) p3++;
			if(p4 < p1) p4++;
			//cout << p2 << " " << p3 << " " << p4 << endl;
			//if(d == 0) cout << tot << endl;
		}
	}

	if(tot%2 == 1) ans += (1 << d);

}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	fr(i, n) cin >> a[i];

	fr(i, 25){
		solve(i);
	}

	cout << ans << endl;
}
