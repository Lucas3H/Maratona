#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1000000007;

int a[212345], n;

int main(){
	rvr(t);
	while(t--){
		scanf("%d", &n);
		vi aux;
		map<int, int> freq;
		fr(i, n){
			scanf("%d", &a[i]);
			aux.pb(a[i]);
			freq[a[i]]++;
		}
		sort(all(aux));
		fr(i, n){
			int pos = (lower_bound(all(aux), MOD - a[i] - 1) - aux.begin());

			if(pos == n){
				if(i != n-1) pos = n-1;
				else pos = n-2;
			}

			else if((a[i] == MOD - a[i] - 1 && freq[a[i]] <= 1) || a[i] != MOD - a[i] - 1){
				if(pos > 0){
					if(pos == n - 1){
						pos--;
					}
					else if((aux[pos - 1] + a[i])%MOD > (aux[n - 1] + a[i])%MOD){
						pos--;
					}
					else pos = n-1;
				}
				else{
					pos = n-1;	
				}
			}

			ll plc = ((ll) a[i] + (ll) aux[pos])%MOD;
			printf("%lld ", plc);
		}
		printf("\n");

	}
}
