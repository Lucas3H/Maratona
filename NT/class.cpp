// https://www.urionlinejudge.com.br/judge/en/problems/view/2788
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
#define INF 1000000000001

ll n, m;
ll restos[2*MAXN], aux[2*MAXN];
ll a[2*MAXN];

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> m;

	fr(i, m) {
		restos[i] = INF;
		aux[i] = INF;
	}
	restos[n%m] = n;

	ll d = ceil((log(n) + 0.000000000001)/log(10));
	ll pow10 = pow(10, d);

	while(restos[0] == INF){
		//cout << "ola" << endl;
		fr(i, m){
			if(restos[i] != INF){
				//cout << restos[i] << " ";
				fr(j, 10){
					ll a = (restos[i]*10 + j)%m;
					aux[a] = min(aux[a], 10*restos[i] + j);
				
					a = (restos[i] + j*pow10)%m;
					aux[a] = min(aux[a], restos[i] + j*pow10);
				}
			}
		}

		//cout << endl;

		fr(i, m){
			restos[i] = aux[i];
			aux[i] = INF;
		}

		d++;
		pow10*=10;
	}

	cout << restos[0] << endl;
}
