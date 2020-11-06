// 
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

vector<pii> lista;
int n;

int main(){
	ios::sync_with_stdio(false);

	cin >> n;
	lista.pb(mp(0, -1));

	int pares = n/2, impares = n - pares;
	int a[MAXN];

	int ans = 0;

	frr(i, n){
		cin >> a[i];

		if(a[i] > 0 && a[i]%2 == 0){
			lista.pb(mp(i, 0));
			pares--;
		}
		else if(a[i]%2 == 1){
			lista.pb(mp(i, 1));
			impares--;
		}
	}

	lista.pb(mp(n + 1, lista[lista.size() - 1].s));
	lista[0] = mp(0, lista[1].s);

	pq<pair<int, pii>> blocos_pares;
	pq<pair<int, pii>> blocos_impares;	

	fr(i, lista.size() - 1){
		if((lista[i].s)%2 == (lista[i+1].s)%2){
			if((lista[i].s)%2 == 0){
				if(lista[i + 1].f != n + 1) blocos_pares.push(mp(-lista[i+1].f + lista[i].f + 1, mp(lista[i].f, lista[i + 1].f)));
				else blocos_pares.push(mp(-lista[i+1].f + lista[i].f + 1, mp(0, -1)));
			}
			else{
				if(lista[i + 1].f != n + 1) blocos_impares.push(mp(-lista[i+1].f + lista[i].f + 1, mp(lista[i].f, lista[i + 1].f)));
				else blocos_impares.push(mp(-lista[i+1].f + lista[i].f + 1, mp(0, -1)));
			}

			ans += 2;
		}
		else ans++;
	}

	int pontas = 2;

	while(!blocos_pares.empty() && -blocos_pares.top().f <= pares){
		pares += blocos_pares.top().f;
		
		if(blocos_pares.top().s.f == 0 || blocos_pares.top().s.s == -1) pontas--;
		
		blocos_pares.pop();

		ans -= 2;
	}

	while(!blocos_impares.empty() && -blocos_impares.top().f <= impares){
		impares += blocos_impares.top().f;

		//cout << blocos_impares.top().s.f << " " << blocos_impares.top().s.s << endl;

		if(blocos_impares.top().s.f == 0 || blocos_impares.top().s.s == -1) pontas--;
		
		blocos_impares.pop();

		ans -= 2;
	}

	if(lista.size() == 2 && n > 1) cout << 1 << endl;
	else if(lista.size() == 2) cout << 0 << endl;
	else cout << ans - pontas << endl;
}
