#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e5 + 10;
const int LMAXN = 25;

int n, q;
int memo[MAXN][LMAXN];
vi mn;

vector<int> tree[4 * MAXN];

void build(int p, int l, int r) {
	if (l == r) return tree[p].push_back(mn[l]);
	int m = (l+r)/2;
	build(2*p, l, m), build(2*p+1, m+1, r);
	merge(all(tree[2*p]), all(tree[2*p+1]), back_inserter(tree[p]));
}

int query(int a, int b, int val, int p=1, int l=0, int r=n-1) {
	if (b < l or r < a) return 0; // to fora
	if (a <= l and r <= b) // to totalmente dentro
		return lower_bound(all(tree[p]), val+1) - tree[p].begin();
	int m = (l+r)/2;
	return query(a, b, val, 2*p, l, m) + query(a, b, val, 2*p+1, m+1, r);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int p[MAXN];
	cin>>n>>q;
	mn.resize(n+1);

  
	frr(i, n){
		cin>>p[i];
		mn[i] = min(i, p[i]);
		memo[i][0] = p[i];
	}

	for (int k = 1; k < LMAXN; k++){
		frr(i, n){
			memo[i][k] = memo[memo[i][k - 1]][k - 1];
			mn[i] = min(mn[i], mn[memo[i][k]]);	
		}
	}


	build(1, 1, n);
	int l, r, ini, fim, meio, best, bval;

	while (q--){
		cin>>l>>r;

		ini = 1; 
		fim = best = n;
		bval = r - l + 1;

		while (ini <= fim){
			meio = (ini + fim)/2;
			//dbg(meio);
			int aux = query(l, r, meio, 1, 1, n); // números <= meio
			int aux2 = (r - l + 1) - aux;

			if (abs(aux - aux2) < bval){
				bval = abs(aux - aux2);
				best = meio;
			}
			if (abs(aux - aux2) == bval)
				best = min(best, meio);

			// dbg(aux);
			// cout<<l<<" "<<r<<endl;
			if (aux >= (r - l + 1)/2) // mais da metade para baixo
				fim = meio - 1;
			else
				ini = meio + 1;
		}

		ini = 1;
		fim = best;

		while (ini <= fim){
			meio = (ini + fim)/2;
			int aux = query(l, r, meio, 1, 1, n); // números <= meio
			int aux2 = (r - l + 1) - aux;
			
			if (abs(aux - aux2) == bval){
				best = min(best, meio);
				fim = meio - 1;
			}
			else
				ini = meio + 1;
		}

		printf("%d\n", best);
	}

}