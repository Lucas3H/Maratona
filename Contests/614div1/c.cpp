#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
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

ll minimo = -1;
ll maximo = -1;

ll x0, y0, ax, ay, bx, by, xs, ys, t;
pair<ll, ll> pt[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	cin >> xs >> ys >> t;

	p[0] = mp(x0, y0);
	
	if(abs(p[0].f - xs) + abs(p[0].s - ys) <= t){
		if(minimo == -1) minimo = 0;
		else maximo = 0;
	}

	frr(i, 63){
		p[i] = mp(ax*p[i].f + bx, ay*p[i].s + by);

		if(abs(p[i].f - xs) + abs(p[i].s - ys) <= t){
			if(minimo == -1) minimo = i;
			else maximo = i;
		}
	}

	ll ans = 0;

	for(int i = minimo; i <= maximo; i++){
		ll path = abs(p[i].f - xs) + abs(p[i].s - ys);
		for(int j = i; j <= maximo; j++){
			if(t - path >= abs(p[j].f - p[i].f) + abs(p[j].s - p[i].s)) 
				ans = max(j - i + 1, ans);
		}
	}

	for(int i = maximo; i >= minimo; i--){
		ll path = abs(p[i].f - xs) + abs(p[i].s - ys);
		for(int j = i; j >= minimo; j--){
			if(t - path >= abs(p[j].f - p[i].f) + abs(p[j].s - p[i].s)) 
				ans = max(j - i + 1, ans);
		}
	}

	cout << ans << endl;
}
