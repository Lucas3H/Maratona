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

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while(t--){
		ll str, in, exp;
		cin >> str >> in >> exp;

		if(in - str >= exp){
			cout << 0 << endl;
			continue;
		}

		if(str <= in){
			exp -= (in + 1 - str);
			str = in + 1;
		}

		ll ans = 0;

		ll m;
		if((str + in + exp)%2 == 0) m = (str + in + exp)/2-1;
		else m = (str + in + exp)/2;
		cout << min(m - in+1, exp+1) << endl;

	}
}
