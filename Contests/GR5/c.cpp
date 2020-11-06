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

#define MAXN 2010
#define MOD 100000001

struct pt{
	ll x, y, z, ind;
};

bool ord(pt a, pt b){
	if(a.x == b.x){
		if(a.y == b.y) return a.z < b.z;
		else return a.y < b.y;
	}
	else return a.x < b.x;
}

ll d(pt a, pt b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z);
}

int main(){
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	pt a[MAXN];
	fr(i, n) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].ind = i + 1;
	}
	sort(a, a + n, ord);

	ll pegos[MAXN];
	fr(i, n) pegos[i] = 0;

	a[n].x = MOD;
	a[n].y = MOD;
	a[n].z = MOD;

	fr(i, n - 1){
		if(pegos[i]) continue;

		ll j = i + 1;

		ll indMin = n;
		ll distMin = d(a[i], a[n]);

		while(j < n){
			if(pegos[j]) j++;
			else{
				if(distMin > d(a[j], a[i])){
					distMin = d(a[j], a[i]);
					indMin = j;
				}				
				j++;
			}
		}

		pegos[i] = 1;
		pegos[indMin] = 1;

		cout << a[i].ind << " " << a[indMin].ind << endl;
	}
}
