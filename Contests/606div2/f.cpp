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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

map<ll, ll> m;
set<ll> a[4*MAXN];

int main(){
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	fr(i, n){
		ll ax;
		cin >> ax;
		m[ax]++;
	}

	for(auto x: m){
		a[x.s].insert(x.f);
	}

	ll total = 0, to_sub = 0;
	fr(i, 4*MAXN) total+=i*a[i].size();

	ll l, c;
	frm(i, 4*MAXN){
		if(total >= i*i){
			l = i;
			c = total/i;

			break;
		}
		else {
			for(auto x: a[i]) a[i-1].insert(x);
			total -= a[i].size();
		}
	}

	pq<pii> fila, prox;
	fr(i, l+1){
		for(auto x: a[i]){
			fila.push(mp(min(i, l), x));
		}
	}

	int ans[1000][1000];

	fr(i, l){
		fr(j, c){
			pii davez = fila.top();
			fila.pop();
			
			ans[i][(i + j)%c] = davez.s;
			davez.f = davez.f - 1;
			if(davez.f == 0) continue;
			prox.push(davez);
		}

		while(!prox.empty()){
			fila.push(prox.top());
			prox.pop();
		}
	}

	cout << l*c << endl;
	cout << l << " " << c << endl;

	fr(i, l){
		fr(j, c) cout << ans[i][j] <<" ";
		cout << endl;
	}
}	
