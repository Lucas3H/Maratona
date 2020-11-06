#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
		ios::sync_with_stdio(false);
		int n, I, a[4*MAXN];
		cin >> n >> I;

		I*=8;

		int k = I/n;

		fr(i, n) cin >> a[i];

		sort(a, a+n);

		int l = 0, r = n-1;

		while(log(a[r] - a[l]) > k*log(2)){
			if(a[r] - a[r-1] > a[l+1] - a[l])r--;
			else l++;
		}

		cout << l + n-1 - r << endl;
}
