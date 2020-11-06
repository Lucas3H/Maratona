#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
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

char m[50][50];
ll r, c;
ll lastBlue[50];
ll firstRed[50];

ll ans[50][50];

void read(){
	cin >> r >> c;
	frr(i, r){
		firstRed[i] = c + 1;
		lastBlue[i] = 0;
		frr(j, c) {
			cin >> m[i][j];
			if(m[i][j] == 'B')
				lastBlue[i] = j;
			else if(m[i][j] == 'R' && firstRed[i] == c + 1){
				firstRed[i] = j;
			}
		}
	}

	ans[r+1][0] = 1;
	lastBlue[0] = 0;
	firstRed[0] = c + 1;
}

void solve(ll linha){
	if(linha < 0) return;
	ll sum = 0;
	for(ll i = 0; i < lastBlue[linha]; i++){
		sum+=ans[linha+1][i];
	}
	ans[linha][lastBlue[linha]] = sum + ans[linha + 1][lastBlue[linha]];
	
	for(ll i = lastBlue[linha] + 1; i < firstRed[linha]; i++){
		ans[linha][i] = ans[linha][i-1] + ans[linha + 1][i];
	}

	solve(linha-1);
}

int main(){
	ios::sync_with_stdio(false);
	read();
	solve(r);
	cout << ans[0][c] << endl;
	/*
	fr(i, r + 1){
		fr(j, c + 1) cout << ans[i][j] <<" ";
		cout << endl;
	}
	*/
}
