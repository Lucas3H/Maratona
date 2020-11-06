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

int a[1000010], maximo[1000010], minimo[1000010];

int main(){
	int test;
	scanf("%d", &test);

	while(test--){
		int n;
		scanf("%d", &n);

		int M = 0;
		fr(i, n) {
			scanf("%d", &a[i]);
			if(a[i] > M) {
				M = a[i];
			}

			maximo[i] = M;
		}

		int m = 1000010;
		for(int i = n-1; i >= 0; i--){
			if(a[i] < m) {
				m = a[i];
			}

			minimo[i] = m;
		}

		int resp = 0;
		for(int i = 1; i < n-1; i++){
			if(minimo[i] == a[i] && maximo[i] == a[i]){
				resp++;
			}
		}

		printf("%d\n", resp);
	}
}
