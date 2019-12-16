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

int color[200200];
int prox[200200];
int pd[200200];
int n;

ll solve(int i){
	if(i >= n-1) return 0;
	if(pd[i] != -1) return pd[i];
	if(prox[i] == -1) return pd[i] = 1 + solve(i+1);

	return pd[i] =  1 + min(solve(i+1),solve(prox[i]));
}



int main(){
	int t;
	scanf("%d", &t);

	while(t--){
	scanf("%d",&n);
	ms(color,-1);
	ms(prox,-1);
	ms(pd,-1);
	fr(i,n) {
		int k;
		scanf("%d", &k);
		if(color[k] != -1){
			//dbg(color[k]);
			prox[color[k]] = i;
		}
		
		color[k] = i;	
	}
	printf("%lld\n", solve(0));
}

	
}

