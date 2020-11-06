#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;
#define ll long long

#define dbg(x)  cout << #x << " = " << x << endl
#define aint(x)  x.begin(),x.end()

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;  
const int mod = 1e9 + 7;


const int MAXN = 1e7;

int lp[MAXN + 10];
vector<int> pr;

void crivo(){
	for (int i = 2; i <= MAXN; i++){
		if (lp[i] == 0){
			lp[i] = i;
			pr.pb(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAXN; j++)
      	  lp[i * pr[j]] = pr[j];
	}
}

vector< pair<int, int> > v;

int32_t main(){
	//chapa;
	crivo(); // peguei todos os primos até 10**7
	//chapa;

	int pos;

//	cout << pr.size() << endl;

	/*
	for (int p : pr){ // pego todos para inclusão exclusão
		pos = v.size();
		for (int i = 0; i < pos; i++){
			int q = v[i].fst;
			if (q * p <= MAXN)
				v.pb({q * p, v[i].snd + 1});
			else break;
		}

		sort(v.begin(), v.end());

		v.pb({p, 1});
	}
	*/
	
	for(int i = 0; i < pr.size(); i++){
		v.pb({pr[i], 1});

		for(int j = 0; j < i; j++){
			if(pr[i]*pr[j] > MAXN) break;

			v.pb({pr[i]*pr[j], 2});

			for(int k = 0; k < j; k++){
				if(pr[j]*pr[i]*pr[k] > MAXN) break;

				v.pb({pr[i]*pr[j]*pr[k], 3});

				for(int l = 0; l < k; l++){
					if(pr[j]*pr[i]*pr[k]*pr[l] > MAXN) break;
					
					v.pb({pr[i]*pr[j]*pr[k]*pr[l], 4});

					for(int x = 0; x < l; x++){
						if(pr[j]*pr[i]*pr[k]*pr[l]*pr[x] > MAXN) break;


						v.pb({pr[i]*pr[j]*pr[k]*pr[l]*pr[x], 5});

						for(int y = 0; y < x; y++){
							if(pr[j]*pr[i]*pr[k]*pr[l]*pr[x]*pr[y] > MAXN) break;


							v.pb({pr[i]*pr[j]*pr[k]*pr[l]*pr[x]*pr[y], 6});

							for(int z = 0; z < y; z++){
								if(pr[j]*pr[i]*pr[k]*pr[l]*pr[x]*pr[y]*pr[z] > MAXN) break;

								v.pb({pr[i]*pr[j]*pr[k]*pr[l]*pr[x]*pr[y]*pr[z], 7});
							}
						}
					}
				}
			}
		}
	}
	
	v.pb({2*3*5*7*11*13*17*19, 8});

	//cout << v.size() << endl;

	int a, b, c, d;

	cin>>a>>b>>c>>d;	

	ll ans = ((ll)b - (ll)a + (ll)1) * ((ll)d - (ll)c + (ll)1);

	ll p, q;
	for (auto x : v){
		p = (b / x.fst) - ((a - 1) / x.fst);
		q = (d / x.fst) - ((c - 1) / x.fst);

		if (x.snd % (ll)2)
			ans -= p * q;
		else
			ans += p * q;
	}

	cout<<ans<<endl;
}