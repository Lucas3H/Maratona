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
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef deque<deque<ll>> matrix;

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

ll n, l, r, t;
set<ll> adj[MAXN];
ll deu = 0, ans = 0;
ll find(ll v, ll pai, ll tam){
	ll achou = 1;
	ll num = 1;

	for(auto x: adj[v]){
		if(x == pai) continue;
		ll aux = find(x, v, tam);
		
		num+=aux;
		if(aux > tam/2)
			achou = 0;
	}

	if(achou && tam - num <= tam/2) deu = v;
	return num;
}

deque<ll> solve(ll root, ll pai, ll tam, ll maximo){
	if(adj[root].size() == 1){
		deque<ll> ret;
		ret.pb(1);
		/*
		cout << "\n----------------\n";
		cout << root << endl;
		cout << 1 << endl;
		cout << "\n----------------\n";
	*/
		return ret;
	}

	adj[root].erase(pai);

	deu = 0;
	ll cent = find(root, root, tam);
	cent = deu;

	deque<deque<ll>> v;
	ll acu[MAXN], l[MAXN];
	
	frr(i, tam) acu[i] = 0;
	acu[0] = 1;

	ll no_maximo = 0;

	for(auto x: adj[cent]){
		deque<ll> aux = solve(x, cent, tam/2, maximo); 
		aux.push_front(0);
	
		fr(i, aux.size()){
			acu[i] += aux[i];
			if(i)aux[i] += aux[i-1];
		}

		v.pb(aux);

		no_maximo = max(no_maximo, (ll)aux.size());
	}

	
	l[0] = 1;
	frr(i, maximo){
		l[i] = acu[i];
		acu[i] += acu[i-1];
	}
	
	ll resp = 0;
	for(auto aux: v){
		ll tl = min((ll)aux.size()-1, maximo);
		

		//cout << resp << endl;

		frr(i, tl){
			resp += (aux[i] - aux[i-1])*(acu[maximo - i] - aux[min(maximo - i, tl)]);
		}
		/*
		cout << resp << endl;

		frr(i, tl){
			cout << aux[i] - aux[i-1] << " | " << acu[maximo - i] - aux[min(maximo - i, tl)] << " coloca " << min(maximo - i, tl) << " ";
		}
		cout << "\n";
		*/
		resp+=aux[tl];
	}

	//cout << root << " " << resp << endl;

	resp/=2;
	ans+=resp;

	adj[root].insert(pai);

	deque<ll> ret;

	fr(i, no_maximo)
		ret.pb(l[i]);
/*
	cout << "\n----------------\n";
	cout << root << endl;
	
	fr(i, no_maximo){
		cout << l[i] << " ";
	}

	cout << "\n----------------\n";
*/
	return ret;
}
ll c = 0;

void read(){
	cin >> n >> l >> r;

	frr(i, n) adj[i].clear();
	fr(i, n-1){
		ll u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	ans = 0;

	deu = 0;
	c = 0;
	ll cent = find((ll)1, (ll)1, n);
	c = deu;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("awesome.in", "r", stdin);

	cin >> t;
	while(t--){
		read();

		if(n == 2){
			if(l == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;

			continue;
		}

		//cout << n - l << " " << n - r - 1 << endl;

		deque<ll> pr = solve(c, c, n, n - 1 - l);
		ll to_prll = ans;
		ans = 0;

		//db;

		pr = solve(c, c, n, n - r - 2);
		to_prll-=ans;

		//db;
		cout << to_prll << endl;
	}
}
