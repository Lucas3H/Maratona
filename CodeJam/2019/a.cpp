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

string s;

void solve(){
	char a[110], b[110];
	
	fr(i, s.size()){
		if(s[i] == '4'){
			a[i] = '3';
			b[i] = '1';
		}
		else{
			a[i] = s[i];
			b[i] = '0';
		}
	}

	int ini = 0;
	while(b[ini] == '0') ini++;
	fr(i, s.size()) cout << a[i];
	cout << ' ';
	for(int i = ini; i < s.size(); i++) cout << b[i];
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	frr(ts, t){
		cin >> s;
		cout << "Case #" << ts << ": ";
		solve();
	}
}
