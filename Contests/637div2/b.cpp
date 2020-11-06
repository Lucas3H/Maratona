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
		int k, n;
		cin >> n >> k;
		int a[2*MAXN];
		frr(i, n){
			cin >> a[i];
		}

		int peaks[2*MAXN];

		peaks[0] = 0;
		for(int i = 2; i <= n-1; i++){
			if(a[i] > a[i-1] && a[i] > a[i+1]) peaks[i] = 1;
			else peaks[i] = 0;
		}

		peaks[n] = 0;

		for(int i = 2; i <= n; i++){
			peaks[i]+=peaks[i-1];
		}

		//frr(i, n) cout << peaks[i] << endl;

		int maior = 1, val = 0;
		for(int i = 1; i <= n - k + 1; i++){
			if(peaks[i + k - 2] - peaks[i] > val){
				maior = i;
				val = peaks[i + k - 2] - peaks[i];
			}
		}

		cout << val + 1 << " " << maior << endl;
	}
}
