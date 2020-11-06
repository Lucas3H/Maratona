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

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int a[MAXN];
	fr(i, n) cin >> a[i];

	int odd = 0;
	fr(i, n){
		if(a[i]%2 == 0) a[i] = a[i]/2;
		else{
			odd++;
			if(odd%2 == 1) a[i] = (a[i]+1)/2;
			else a[i] = (a[i]- 1)/2;
		}

		cout << a[i] << endl;
	}

}
