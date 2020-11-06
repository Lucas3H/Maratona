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

#define MAXN 1000010
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	while(t--){
		ll tam = 0, x;
		char c;
		char aux[MAXN], s[MAXN];
		cin >> x >> aux;

		tam = strlen(aux);

		frr(i, tam) s[i] = aux[i-1];

		frr(i, x){
			if(s[i] == '2'){
				int j = i + 1; 
				while(tam + j - i <= x && j <= tam){
					 s[tam + j - i] = s[j];
					 j++;
				}

				tam = (tam + tam - i + MOD)%MOD;
			}

			else if(s[i] == '3'){
				int j = i + 1; 
				while(tam + j - i <= x && j <= tam){
					 s[tam + j - i] = s[j];
					 j++;
				}

				j = i + 1;
				while(2*tam + j - 2*i <= x && j <= tam){
					 s[2*tam + j - 2*i] = s[j];
					 j++;
				}

				tam = (tam + 2*tam - 2*i + 2*MOD)%MOD;
			}
		}

		cout << tam << endl;
	}
}
