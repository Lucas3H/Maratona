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
#define INF 987654321

ll v[MAXN], bit_y[MAXN];
ll n, l, d_min = MOD;

ponto p[MAXN];
ll inv[MAXN];

void update(ll i, ll val){
    while(i <= n){
        bit_y[i] += val;
        i += i & (-i);
    }
}

ll query(ll i){
    ll sum = 0;

    while(i > 0){
        sum += bit_y[i];
        i -= i & (-i);
    }

    return sum;
}

ll binary_search(ll val){
	ll sum = 0, pos = 0;
	
    ll i = LOGN;

	while(i >= 0){
		if(pos + (1 << i) < n && sum + bit_y[pos + (1 << i)] < val){
			sum += bit_y[pos + (1 << i)];
			pos += (1 << i);
		}

        i--;
	}

	return pos + 1; 
}

void restart(){
    fr(i, MAXN+1) bit_y[i] = 0;

	l = 1;
}

ll read(){
	cin >> n;

	if(n == 0) return 0;

	frr(i, n) cin >> p[i].f >> p[i].s;

	sort(p + 1, p + n + 1);	

	frr(i, n){
		inv[p[i].s] = i;
	}

	return 1;
}

ll dist(ponto a, ponto b){
	return (a.f - b.f)*(a.f - b.f) + (a.s - b.s)*(a.s - b.s);
}

void solve(){
	pair<ll, ll> closest;

	update(p[1].s, 1);
	update(MAXN, 1);

	for(ll i = 2; i <= n; i++){
		while(d_min < (p[i].f - p[l].f)*(p[i].f - p[l].f)){
			update(p[l].s, -1);
			l++;
		}

		int ini = binary_search(p[i].s - sqrt(d_min));

		for(int it = 0; it < 8 && {
			if(d_min > dist(p[i], p[ini])){
				closest
			}
	
		}
	}
}

int main(){
}
