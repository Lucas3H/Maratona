#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

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

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		int menor = MOD, maior = 0;
	
		int a[MAXN];
		frr(i, n){
			cin >> a[i];
		}

		frr(i, n){
			if(a[i] == -1){
				if(i > 1 && a[i-1] != -1){
					menor = min(menor, a[i-1]);
					maior = max(maior, a[i-1]);
				}

				if(i < n && a[i+1] != -1){
					menor = min(menor, a[i+1]);
					maior = max(maior, a[i+1]);
				}
			}
		}

		int m = (maior + menor)/2;

		frr(i, n){
			if(a[i] == -1) a[i] = m;
		}

		int d = 0;

		frr(i, n-1){
			d = max(d, abs(a[i] - a[i+1]));
		}

		cout << /*maior << " " << menor << " " <<*/ d << " " << m<< endl;
	}
}
