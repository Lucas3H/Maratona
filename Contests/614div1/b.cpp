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
typedef vector<vector<ll>> matriX;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq prioritY_queue

#define mX(a, b) a = maX(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 20000000000000000

ll minimo = -1;
ll maXimo = -1;

ll X0, Y0, aX, aY, bX, bY, Xs, Ys, t;
pair<ll, ll> p[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin >> X0 >> Y0 >> aX >> aY >> bX >> bY;
	cin >> Xs >> Ys >> t;

	p[0] = mp(X0, Y0);
	
	if(abs(p[0].f - Xs) + abs(p[0].s - Ys) <= t){
		if(minimo == -1) minimo = 0;
		maXimo = 0;
	}

	//cout << p[0].f << " " << p[0].s << " " << aX << " " << bX << endl;

	int para = 0;

	frr(i, 63){
		p[i] = mp(aX*p[i - 1].f + bX, aY*p[i - 1].s + bY);

		if(p[i].f >= INF || p[i].s >= INF){
			para = i;
			break;
		}

		if(abs(p[i].f - Xs) + abs(p[i].s - Ys) <= t){
			if(minimo == -1) minimo = i;
			maXimo = i;
		}
	}

	ll ans = 0;
/*	fr(i, para + 1){
		cout << p[i].f << " " << p[i].s << endl;
	}

	cout << maXimo << ' ' << minimo << endl;
*/
	for(ll i = minimo; i <= maXimo; i++){
		ll path = abs(p[i].f - Xs) + abs(p[i].s - Ys), dist = path;
		for(ll j = i; j <= maXimo; j++){
			if(t - path >= abs(p[j].f - p[i].f) + abs(p[j].s - p[i].s)){
				ans = max(j - i + 1, ans);
				dist = path + abs(p[j].f - p[i].f) + abs(p[j].s - p[i].s);

				for(ll k = j; k >= minimo; k--){
					if(t - dist >= abs(p[k].f - p[j].f) + abs(p[k].s - p[j].s)){
						ans = max(j - k + 1, ans);
					}
				}
			}
		}
	}

	for(ll i = maXimo; i >= minimo; i--){
		ll path = abs(p[i].f - Xs) + abs(p[i].s - Ys), dist;
		for(ll j = i; j >= minimo; j--){
			if(t - path >= abs(p[j].f - p[i].f) + abs(p[j].s - p[i].s)){
				ans = max(i - j + 1, ans);
			
				dist = path + abs(p[j].f - p[i].f) + abs(p[j].s - p[i].s);

				for(ll k = j; k <= maXimo; k++){
					if(t - dist >= abs(p[k].f - p[j].f) + abs(p[k].s - p[j].s)){
						ans = max(k - j + 1, ans);
					}
				}
			} 
		}		
	}
/*
	for(int i = minimo; i <= maXimo; i++){
		cout << p[i].f << " " << p[i].s << endl;
	}
*/
	//cout << maXimo << " " << minimo << endl;

	if(minimo > -1) cout << ans << endl;
	else cout << 0 << endl;
}
