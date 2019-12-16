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

int fatorial(int n){
	int resp = 1;
	for(int i = 2; i <= n; i++) resp *= i;

	return resp;
}

int a[256];

int main(){
	int test;
	scanf("%d", &test);

	while(test--){
		int n;
		scanf("%d", &n);
		string s;
		cin >> s;

		memset(a, 0, sizeof(a));
		fr(i, n) {
			a[(int)s[i]]++;
		}

		int impar = 0;
		for(int i = 97; i < 123; i++){
			if(a[i]%2 == 1) impar++;
			a[i] = a[i]/2;
		}

		
		if(impar > 1) printf("%d\n", 0);
		else{
			n = n/2;
			int resp = fatorial(n);
			for(int i = 97; i < 123; i++){
				resp = resp/fatorial(a[i]);
			}

			printf("%d\n", resp);
		}

	}
}