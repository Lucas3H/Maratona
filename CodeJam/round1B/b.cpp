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
#define MOD (ll)1000000000
#define MAXL 30
#define ROOT 1
#define INF 987654321

string s;
ll t, a, b;

pii ini(){
	cout << 0 << " " << 0 << endl;
	cin >> s;

	if(s == "CENTER")
		return mp(MOD, MOD);
	if(s == "HIT")
		return mp(0, 0);

	cout << -MOD/2 << " " << -MOD/2 << endl;
	cin >> s;

	if(s == "CENTER")
		return mp(MOD, MOD);
	if(s == "HIT")
		return mp(-MOD/2, -MOD/2);

	cout << -MOD/2 << " " << MOD/2 << endl;
	cin >> s;

	if(s == "CENTER")
		return mp(MOD, MOD);
	if(s == "HIT")
		return mp(-MOD/2, MOD/2);

	cout << MOD/2 << " " << MOD/2 << endl;
	cin >> s;

	if(s == "CENTER")
		return mp(MOD, MOD);
	if(s == "HIT")
		return mp(MOD/2, MOD/2);

	cout << MOD/2 << " " << -MOD/2 << endl;
	cin >> s;

	if(s == "CENTER")
		return mp(MOD, MOD);
	if(s == "HIT")
		return mp(MOD/2, -MOD/2);

	return mp(MOD, MOD);
}

pii dir(pii p0){
	ll ini = p0.f, fim = min(p0.f + 2*b + 1, MOD), meio;

	while(ini < fim - 1){
		meio = (ini+fim)/2;
		cout << meio << " " << p0.s << endl;
		cin >> s;

		if(s == "CENTER")
			return mp(MOD, MOD);

		else if(s == "HIT")
			ini = meio;
		else 
			fim = meio;
	}

	return mp(ini, p0.s);
}

pair<pii, pii> prox(pii p0){
	ll ini, fim, meio, tipo = 0;
	pii v1, v2;
	
	cout << p0.f << " " << p0.s + 1 << endl;
	cin >> s;

	if(s == "CENTER")
		return mp(mp(MOD, MOD), mp(MOD, MOD));


	ini = p0.s;
	fim = min(p0.s + 2*b + 1, MOD);
	
	while(ini < fim - 1){
		meio = (ini+fim)/2;
		cout << p0.f << " " << meio << endl;
		cin >> s;

		if(s == "CENTER")
			return mp(mp(MOD, MOD), mp(MOD, MOD));

		else if(s == "HIT")
			ini = meio;
		else 
			fim = meio;
	}

	v1 = mp(p0.f, ini);

	fim = p0.s;
	ini = max(p0.s - 2*b - 1, -MOD);	
	tipo = 1;	
	
	while(ini < fim - 1){
		meio = (ini+fim)/2;
		cout << p0.f << " " << meio << endl;
		cin >> s;

		if(s == "CENTER")
			return mp(mp(MOD, MOD), mp(MOD, MOD));

		else if(s == "HIT")
			fim = meio;
		else 
			ini = meio;
	}
	
	v2 = mp(p0.f, fim);

	return mp(v1, v2);
}

pii esq(pii p0){
	ll ini = max(p0.f - 2*b - 1, -MOD), fim = p0.f, meio;

	while(ini < fim - 1){
		meio = (ini+fim)/2;
		cout << meio << " " << p0.s << endl;
		cin >> s;

		if(s == "CENTER")
			return mp(MOD, MOD);

		else if(s == "HIT")
			fim = meio;
		else 
			ini = meio;
	}

	return mp(fim, p0.s);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> t >> a >> b;

	while(t--){
		pii comeco = ini();

		if(comeco.f == MOD)
			continue;

		pii direita = dir(comeco);

		if(direita.f == MOD)
			continue;

		pair<pii, pii> proximo = prox(direita);

		if(proximo.f.f == MOD)
			continue;
		
		pii esquerda = esq(proximo.f);
		if(esquerda.f == MOD)
			continue;
 
		ll x0 = (esquerda.f + proximo.s.f)/2, y0 = (esquerda.s + proximo.s.s)/2;

		for(int i = -1; i <= 1; i++){
			int achou = 0;
			for(int j = -1; j <= 1; j++){
				cout << x0 + i << " " << y0 + j << endl;
				cin >> s;

				if(s == "CENTER"){
					achou = 1;
					break;
				}
			}

			if(achou) break;
		}
	}
}
