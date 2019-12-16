#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 1000010
#define MOD 1000000007

int v[MAXN];
vector<int> p;

/*
int maxpot(ll n, ll base){
		ll ans = 1;
		int e = 0;

		if(n == 1) return 0;

		while(ans < n){
				e++;
				ans*=base;
		}
		e--;

		return e;
}*/
#define eps 0.1
int main(){
		ios::sync_with_stdio(false);

		for(int i = 2; i < MAXN; i++){
				if(v[i] == 0){
						p.pb(i);
						for(int j = 2*i; j < MAXN; j+=i) v[j] = 1;
				}
		}

		int t;
		cin >> t;

		while(t--){
				ll l, r;
				cin >> l >> r;

				ll resp = 0;
				for(int i = 0; i < p.size(); i++){
						int a = floor(log(r+eps)/log(p[i]));
						int b;
						if(l == 1) b = 0;
						else b = floor(log(l-eps)/log(p[i]));

						if(b == 0 && a > 0) resp += (ll)a-1;
						else resp += (ll)(a) - (ll)b;
					  //cout << p[i] << " " << resp << endl;
				}

				cout << resp << endl;
		}
}
