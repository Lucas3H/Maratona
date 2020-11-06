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


	int fined[MAXN], a[MAXN], b[MAXN];
	fr(i, n) fined[i] = 0;

	fr(i, n) cin >> a[i];
	fr(i, n) cin >> b[i];

	int i = 0, j = 0;
	int ans = 0;

	while(i < n-1  && j < n-1){
		if(a[i] == b[j]){
			i++;
			j++;
		}
		else if(fined[a[i]]) i++;
		else{
			fined[b[j]] = 1;
			j++;
			ans++;
		}
	}

	cout << ans << endl;
}
