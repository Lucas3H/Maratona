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
#define INF 987654321

int gd[110][110];

int find(set<int> a){
	int ind = 0;
	for(auto x: a){
		if(x > ind) return ind;
		ind++;
	}

	return ind;
}

void build(){
	frr(i, 100){
		frr(j, 100){
			if(i == j) continue;

			set<int> pos;

			for(int k = 1; k < i; k++){
				if(i - k != j)
					pos.insert(gd[i - k][j]);
			}

			for(int k = 1; k < j; k++)
				if(i != j - k)
					pos.insert(gd[i][j - k]);
		
			for(int k = 1; k < min(i, j); k++)
				pos.insert(gd[i - k][j - k]);
		
			gd[i][j] = find(pos);
		}
	}
}


int main(){
	ios::sync_with_stdio(false);

	build();

/*	frr(i, 10){
		fr(j, 10) cout << gd[i][j] <<" ";
		cout << endl;
	}
*/
	int n;
	cin >> n;

	int deu = 0;

	frr(i, n){
		int l, c;
		cin >> l >> c;

		if(l == c){
			cout << "Y\n";
			return 0;
		}

		deu ^= gd[l][c];
	}

	if(deu == 0){
		cout << "N\n";
	}
	else{
		cout << "Y\n";
	}
}
