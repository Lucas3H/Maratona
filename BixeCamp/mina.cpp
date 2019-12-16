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

#define MAXN 101

int mina[MAXN][MAXN], processado[MAXN][MAXN], dist[MAXN][MAXN];

int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
int n;

void bfs(int X, int Y){
	pq<pair<int, pii>> fila;
	fila.push(mp(0, mp(X, Y)));

	while(true){
		pii davez = mp(-1, -1);
		int D = 1;

		while(!fila.empty()){
			int x = fila.top().second.first;
			int y = fila.top().second.second;

			if(!processado[x][y]){
				davez = mp(x, y);
				processado[x][y] = 1;
				D = fila.top().first;
				fila.pop();
				break;
			}
			else fila.pop();
		}

		if(davez == mp(-1, -1)) break;

		fr(i, 4){
			int x = mx[i] + davez.first, y = my[i] + davez.second;

			if(x < 0 || y < 0 || x >= n || y >= n) continue;

			if(!processado[x][y] && mina[x][y] == 0){
//				cout << x << " " << y << endl;

				dist[x][y] = D;
				fila.push(mp(D, mp(x, y)));  
			}
			else if(!processado[x][y] && mina[x][y] == 1){
//				cout << x << " " << y << endl;

				dist[x][y] = D - 1;
				fila.push(mp(D - 1, mp(x, y)));
			}
		}
	}
}

int main(){
	cin >> n;

	mem(processado, 0);
	mem(dist, -1);

	fr(i, n){
		fr(j, n) cin >> mina[i][j];
	}

	bfs(0, 0);

	cout << -dist[n-1][n-1] << endl;

	return 0;
}