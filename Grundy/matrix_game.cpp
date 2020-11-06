// https://www.spoj.com/problems/MATGAME/
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

int mex(int v[], int tam){
	int ans = 0;
	ans = v[tam];
	for(int i = tam - 1; i > 0; i--){
		if(v[i] == 1){
			if(v[i+1] > 1) ans = 0;
			else ans = 1 - ans;
		}
		else{
			if(ans >= v[i]) ans = v[i] - 1;
			else ans = v[i];
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		int R, C;
		cin >> R >> C;
		int m[52][52];


		int sum = 0;
		frr(i, R){
			frr(j, C) cin >> m[i][j];
		
			sum^=mex(m[i], C);
		}

		if(sum == 0) cout << "SECOND\n";
		else cout << "FIRST\n";
	}
}
