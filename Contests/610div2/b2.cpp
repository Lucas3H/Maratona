// 
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
typedef pair<int, int> ponto;
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

int n, P, k;
int main(){
	ios::sync_with_stdio(false);
	int t;
	scanf("%d", &t);

	while(t--){
		scanf("%d %d %d", &n, &P, &k);

		int a[2*MAXN], aux;
		int m[2*MAXN];
		fr(i, k) m[i] = 0;

		frr(i, n) {
			scanf("%d", &a[i]);
		}

		a[n+1] = MOD;

		sort(a + 1, a + n + 2);

		int ans = 0;

		m[0] = 0;
		frr(i, k-1){
			m[i] = m[i-1]+a[i];
			if(m[i%k] <= P) ans = max(ans, i);
		}

		for(int i = k; i <= n; i++){
			m[i%k]+=a[i];
			if(m[i%k] <= P) ans = max(ans, i);
		}

		printf("%d\n", ans);


	}

}
