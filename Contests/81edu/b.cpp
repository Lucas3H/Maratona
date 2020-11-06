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
	int t;
	cin >> t;

	while(t--){
		int n, x;
		cin >> n >> x;

		string s;
		cin >> s;

		int saldo = 0, saldo_min = 0, saldo_max = 0;
		fr(i, n){
			if(s[i] == '0') saldo++;
			else saldo--;

			saldo_min = min(saldo_min, saldo);
			saldo_max = max(saldo_max, saldo);
		}

		int saldo_aux = 0, ans = 0;
		fr(i, n){
			if(saldo > 0 && saldo_aux <= x && (saldo_aux - x)%saldo == 0) ans++;
			else if(saldo < 0 && saldo_aux >= x && (saldo_aux - x)%saldo == 0) ans++;

			if(s[i] == '0') saldo_aux++;
			else saldo_aux--;
		}
/*
		if(saldo > 0 && saldo_aux <= x && (saldo_aux - x)%saldo == 0) ans++;
		else if(saldo < 0 && saldo_aux >= x && (saldo_aux - x)%saldo == 0) ans++;
*/
		if(saldo == 0 && (saldo_min > x || saldo_max < x)) cout << 0 << endl;
		else if(saldo == 0) cout << -1 << endl;
		else cout << ans << endl;
	}
}
