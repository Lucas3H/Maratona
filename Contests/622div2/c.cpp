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

#define MAXN 500010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

class NSE{
    public:
        void nse(ll v[], ll n, ll ret[], ll ind){
            for(ll i = 0; i < n; i++){
                ret[i] = -1;
            }

            stack<ll> s;

			if(ind == 0){
		        for(ll i = n-1; i >= 0; i--){
                	while(!s.empty() && v[s.top()] > v[i]){
                    	ret[s.top()] = i;
                    	s.pop();
                	}

					s.push(i);
            	}
			}
			else{
		        for(ll i = 0; i < n; i++){
                	while(!s.empty() && v[s.top()] > v[i]){
                    	ret[s.top()] = i;
                    	s.pop();
                	}

					s.push(i);
            	}
			}
        }
};

ll n;
NSE novo;
ll nse1[MAXN], nse2[MAXN], v[MAXN], dp1[MAXN], dp2[MAXN];;

void build(){
	cin >> n;

	fr(i, n){
		cin >> v[i];
	}

	novo.nse(v, n, nse1, 0);
	novo.nse(v, n, nse2, 1);
}	

int main(){

	build();

/*nse1 é a proximo a esquerda e nse2 é proximo a direita*/

	dp1[0] = v[0];
	dp2[n-1] = v[n-1];

	for(ll i = 1; i < n; i++){
		if(nse1[i] == -1){
			dp1[i] = (i+1)*v[i];
		}
		else{
			dp1[i] = (i - nse1[i])*v[i] + dp1[nse1[i]];
		}
	}

	for(ll i = n-2; i >= 0; i--){
		if(nse2[i] == -1){
			dp2[i] = (n - i)*v[i];
		}
		else{
			dp2[i] = (nse2[i] - i)*v[i] + dp2[nse2[i]];
		}
	}
/*
	fr(i, n){
		cout << dp1[i] <<" " << dp2[i] << endl;
	}*/

	ll ans = 0;

	for(ll i = 0; i < n; i++){
		if(dp1[ans] + dp2[ans] - v[ans] < dp1[i] + dp2[i] - v[i]) ans = i;
	}

	ll l[MAXN];
	l[ans] = v[ans];

	for(ll i = ans - 1; i >= 0; i--){
		l[i] = min(l[i + 1], v[i]);
	}


	for(ll i = ans + 1; i < n; i++){
		l[i] = min(l[i - 1], v[i]);
	}

	fr(i, n) cout << l[i] <<" ";
	cout << endl;

}