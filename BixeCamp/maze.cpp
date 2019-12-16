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

#define MAXN 510

char m[MAXN][MAXN];
int processado[MAXN][MAXN], grau[MAXN][MAXN];
pii pai[MAXN][MAXN];
int n, M, k;
	
int dir[][2] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

void dfs(int i, int j) {
	processado[i][j] = 1;

	int dg = 0;

	for (int k = 0; k < 4; k++) {
		int ni = i + dir[k][0];
		int nj = j + dir[k][1];

		if(ni > n-1 || ni < 0 || nj > M-1 || nj < 0 ) continue;

		if(processado[ni][nj] == 0 && m[ni][nj] == '.'){
			pai[ni][nj] = mp(i, j);
			dg++;
			dfs(ni, nj); 
		}

	}

	grau[i][j] = dg + 1;
}
/*
void transformacao(int i, int j){
	if(grau[i][j] > 1) return;
	if(i == X && j == Y) return;
	if(k == 0) return;
	if(m[i][j] != '.') return;

	m[i][j] = 'X';
	k--;
	grau[i][j] = 0;

	int x = pai[i][j].first, y = pai[x][y].second;
	grau[x][y]--;

	transformacao(x, y);
}*/

int main(){
	cin >> n >> M >> k;

	mem(processado, 0);
	mem(grau, 0);

	int X = -1, Y = -1;


	fr(i, n){
		fr(j, M) {
			cin >> m[i][j];
			if(m[i][j] == '.'){
				X = i;
				Y = j;
			}
		}
	}

	dfs(X, Y);
	grau[X][Y]--;
	//pai[X][Y]

	stack<pii> grau_1; 

	fr(i, n){
		fr(j, M){
			if(grau[i][j] == 1) grau_1.push(mp(i, j));
		}
	}


	while(k > 0){
	
		int x = grau_1.top().first, y = grau_1.top().second;
		grau_1.pop();

		m[x][y] = 'X';
		k--;
		grau[x][y] = 0;


		if(x == X && y == Y) continue;

		int r = pai[x][y].first, s = pai[x][y].second;	
		
		grau[r][s]--;

		if(grau[r][s] == 1) grau_1.push(mp(r, s));
	}

	fr(i, n){
		fr(j, M) cout << m[i][j];

		cout << endl;
	}
}

