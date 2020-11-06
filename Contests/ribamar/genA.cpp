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

	string s;
	cin >> s;

	int a[50];
	fr(i, 50) a[i] = 0;
	fr(i, s.size()) a[i] = s[i] - '0';

	int ans[50];

	for(int i = 0; i < 2*s.size()-1; i++){
		int sum = 0;

		for(int j = 0; j < i+1; j++){
			sum = (sum + (a[j]*a[i-j])%10)%10;
		}

		ans[i] = sum%10;
	}

	fr(i, 2*s.size()-1) cout << ans[i];
	cout << endl;
}
