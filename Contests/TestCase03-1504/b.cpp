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


int a[1123], n, m, t, out, first = INF;

int main(){

	scanf("%d", &t);
	while(t--){
		
		scanf("%d%d", &n, &m);

		fr(i, n){
			scanf("%d", &a[i]);
			if(a[i] != -1){
				first = min(first, i);
			}
		}

		int start = first - 1, end = first + 1;

		while(start >= 0){
			a[start] = (a[start+1] - 1)%m;
			if(a[start] < 0) a[start] += m;
			start--;
		}
		while(end < n){
			a[end] = (a[end-1] + 1)%m;
			end++;
		}

		fr(i, n) printf("%d ", a[i]);
		printf("\n");

		first = INF;
	}

}