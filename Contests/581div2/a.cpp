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

		string s;
		cin >> s;

		int zero = 1;
		frr(i, s.size()-1) if(s[i] == '1') zero = 0;


		if(s.size()%2 == 1 && zero) cout << (s.size() - 1)/2 << endl;
		else if(s.size()%2 == 1) cout << (s.size() + 1)/2 << endl;
		else cout << (s.size() + 1)/2 << endl;
}
