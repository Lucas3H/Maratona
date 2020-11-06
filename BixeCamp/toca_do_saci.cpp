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

#define MAXN 1010
#define M 1001000

int s[MAXN][MAXN], dist[MAXN][MAXN], processado[MAXN][MAXN];
int n, m;

void dfs(int x, int y){
	processado[x][y] = 1;

	if(s[x][y] == 0) return;

	if(s[x-1][y] != 0 && processado[x-1][y] == 0){

		dist[x-1][y] = min(dist[x][y] + 1, dist[x-1][y]);
		dfs(x-1, y);
	}

	if(s[x+1][y] != 0 && processado[x+1][y] == 0){
	
		dist[x+1][y] = min(dist[x][y] + 1, dist[x+1][y]);
		dfs(x+1, y);
	}

	if(s[x][y-1] != 0 && processado[x][y-1] == 0){
	
		dist[x][y-1] = min(dist[x][y] + 1, dist[x][y-1]);
		dfs(x, y-1);
	}

	if(s[x][y+1] != 0 && processado[x][y+1] == 0){
	
		dist[x][y+1] = min(dist[x][y] + 1, dist[x][y+1]);
		dfs(x, y+1);
	}
}

int main(){
	cin >> n >> m;

	fr(i, n+2){
		fr(j, m+2) dist[i][j] = M;
	}
	mem(dist, M);
	mem(processado, 0);

	frr(i, n){
		s[i][0] = 0;
		s[i][n+1] = 0;
	}

	frr(i, m){
		s[0][i] = 0;
		s[m+1][i] = 0;
	}

	int x1, x2, y1, y2;

	frr(i, n){
		frr(j, m){
			cin >> s[i][j];

			if(s[i][j] == 2){
				x1 = i;
				y1 = j;
			}
			else if(s[i][j] == 3){
				x2 = i;
				y2 = j;
			}	
		}
	}

	dist[x1][y1] = 1;
	dfs(x1, y1);

	cout << dist[x2][y2] << endl;

}
