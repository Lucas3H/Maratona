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

#define MAXN 100010

int mx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int my[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int dist[8][8], processado[8][8];

void bfs(int l, int c){
	pq<pair<int, pii>> fila;
	fila.push(mp(0, mp(l, c)));

	while(true){
		pii davez = mp(-1, -1);

		while(!fila.empty()){
			int L = fila.top().second.first, C = fila.top().second.second;
			fila.pop();

			if(!processado[L][C]){
				davez = mp(L, C);
				processado[L][C] = 1;
				break;
			}
		}

		if(davez == mp(-1, -1)) break;

//		cout << davez.first << " " << davez.second << endl;

		fr(i, 8){
			int il = davez.first+my[i], ic = davez.second+mx[i];

			if(il >= 8 || il < 0 || ic >= 8 || ic < 0) continue;

			if(!processado[il][ic]){
				dist[il][ic] = dist[davez.first][davez.second] + 1;
				fila.push(mp(-dist[il][ic], mp(il, ic)));
			}
		}
	}
}

int main(){
	int t;
	cin >> t;

	while(t--){
		string ini, fim;
		cin >> ini >> fim;

		int ix = int(ini[0]) - 97, iy =  7 - int(ini[1]) + 49;	
		int fx = int(fim[0]) - 97, fy =  7 - int(fim[1]) + 49;
	
		mem(dist, -1);
		mem(processado, 0);
		dist[iy][ix] = 0;

		bfs(iy, ix);

		cout << dist[fy][fx] << endl;
	}

	return 0;
}