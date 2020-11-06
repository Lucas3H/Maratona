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
int v[50][50];


int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		
		cin >> n >> m;
		fr(i,n){
			string s;
			cin >> s;
			fr(j,m){
				v[i][j] = s[j] - '0';
			}
		}
		ll zero = 0;
		ll rest = 0;
		fr(i,m){
			if(v[0][i] == 0) zero++;
			if(v[n-1][i] == 0) zero++;
		}
		fr(i,n){
			if(v[i][0] == 0) zero++;
			if(v[i][m-1] == 0) zero++;

		}
		if(v[0][0] == 0) zero--;
		if(v[n-1][0] == 0) zero--;
		if(v[0][m-1] == 0) zero--;
		if(v[n-1][m-1] == 0) zero--;

		

		fr(i,n){
			fr(j,m){
				if(i==0 || i==n || j==0 || j==m-1) continue;
				if(v[i][j] == 1) rest++;
			}
		}

		if(rest >= zero) cout << zero << "\n";
		else cout << -1 << "\n";

	}
	int n,m;

}
