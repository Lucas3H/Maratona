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
typedef pair<ll, ll> pll;
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
#define INF 1000000000000000100

string s, t;
int n, m;

int deu(int pos){
	char cor[2] = {'-', '-'};
	for(int i = 0; i < m; i++){
		if(cor[t[i] - '0'] == '-'){
			cor[t[i] - '0'] = s[pos + i];
		}
		else{
			if(cor[t[i] - '0'] != s[pos + i]){
				return 0;
			}
		}
	}

	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> s >> t;
	n = s.size(), m = t.size();

	int ans = 0;

	fr(i, n - m + 1){
		//cout << i << endl;
		if(deu(i)){
			ans++;
			continue;
		}

		reverse(t.begin(), t.end());
		if(deu(i)){
			ans++;
		}
		reverse(t.begin(), t.end());
	}

	cout << ans << endl;
}
