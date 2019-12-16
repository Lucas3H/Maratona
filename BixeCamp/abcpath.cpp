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

#define MAXN 52

int h, w;
char tab[MAXN][MAXN];
int processado[MAXN][MAXN], dist[MAXN][MAXN];

int mx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int my[8] = {-1, 1, 0, -1, 1, 0, 1, -1};

void dfs(int X, int Y){
	priority_queue<pair<int, pii>/*, vector<pair<int, pii>, greater<pair<int, pii>*/> fila;
	fila.push(mp(0, mp(X, Y)));

	while(true){
		pii davez = mp(-1, -1);
		int D = -1;

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

		fr(i, 8){
			int x = mx[i] + davez.first, y = my[i]+ davez.second;

			if(x < 0 || y < 0 || x >= h || y >= w) continue;

			if(!processado[x][y] && int(tab[x][y]) == int(tab[davez.first][davez.second]) + 1){
				
			//	if(tab[x][y] == 'B') cout << "B " <<davez.first << " " << davez.second <<  endl;

				dist[x][y] = D + 1;
				fila.push(mp(D + 1, mp(x, y)));

			}
		}
	} 
}

int main(){
	cin >> h >> w;

	int caso = 0;

	while(h != 0 && w != 0){
		caso++;
		stack<pii> A;

		fr(i, h){
			fr(j, w) {
				cin >> tab[i][j];
				if(tab[i][j] == 'A') A.push(mp(i, j));
				processado[i][j] = 0;
				dist[i][j] = -1;
			}
		}

		while(!A.empty()){
			int x = A.top().first, y = A.top().second;
			dist[x][y] = 0;

			dfs(x, y);

			A.pop();
		}

		int MAX = -1, ix, iy;
		fr(i, h){
			fr(j, w){
			//	cout << dist[i][j] << " ";

				if(dist[i][j] > MAX){
					ix = i;
					iy = j;
					MAX = dist[i][j];
				}
			}
		//	cout << endl;
		}
/*
		fr(i, h){
			fr(j, w) cout << processado[i][j] << ' ';

			cout << endl;
		}*/

		cout << "Case "<< caso << ": " << MAX + 1 << endl;
	
		cin >> h >> w;
	}

	return 0;
}