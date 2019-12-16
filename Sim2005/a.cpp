#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 10001
#define MOD 1000000007

ll pas[MAXN][MAXN];

int pascal(int linha, int coluna){
	if(linha == 0 && coluna == 0) return 1;
	if(coluna == 0 || coluna == linha) return 1;

	if(coluna > linha/2) coluna = linha - coluna;

	if(pas[linha][coluna] != -1) return pas[linha][coluna];

	ll resp = pas[linha-1][coluna] + pas[linha-1][coluna-1];
	resp = resp%MOD;

	return pas[linha][coluna] = resp;
}

int main(){
	int tests;
	cin >> tests;

	int inv2 = (MOD + 1)/2;

	ll inv[MAXN];

	inv[0] = 1;
	frr(i, MAXN-1) {
		inv[i] = inv2*inv[i-1];
		inv[i] = inv[i]%MOD;
	}

	mem(pas, -1);

	while(tests--){
		int n, m;

		cin >> n >> m;

		n = abs(n);

		if(n > m || (m - n)%2 == 1){
			cout << -1 << endl;
			continue;
		}

		int k = (m - n)/2;

		ll resp = 1;

		frr(i, k){
			resp *= m;
			resp /= i;

			resp = resp%MOD;
			m--;
		}

		resp = resp*inv[m];
		resp = resp%MOD;

		cout << resp << endl;
	}
}