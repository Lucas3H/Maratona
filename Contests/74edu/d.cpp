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

ll n;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> s;

	ll ini[3*MAXN], fim[3*MAXN];
	ll tot = 0;
	ini[0] = 0;

	fr(i, n-1){
		if(s[i] == s[i+1]) continue;
		else{
			fim[tot++] = i;
			ini[tot] = i+1;
		}
	}

	fim[tot] = n-1;

	ll ans = 0;
	fr(i, tot) ans+=(fim[i] - ini[i]+1);
	frr(i, tot) ans+=(fim[i] - ini[i]);


	cout << n*(n-1)/2 - ans << endl;
}
