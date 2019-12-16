#include <bits/stdc++.h>
#define INF 10000000

using namespace std;

int m[1010][1010], d[1010][1010];
int rows, columns; 

void dfs(int x, int y){ 
	//cout << x << " " << y << endl;
	
	if(m[x-1][y] > 0 && d[x-1][y] < 0) {
		d[x-1][y] = d[x][y] + 1;
		dfs(x-1, y);	
	}  
	if(m[x+1][y] > 0 && d[x+1][y] < 0){
		d[x+1][y] = d[x][y] + 1;
		dfs(x+1, y);
	}
	if(m[x][y-1] > 0 && d[x][y-1] < 0){
		d[x][y-1] = d[x][y] + 1;
		dfs(x, y-1);
	}
	if(m[x][y+1] > 0 && d[x][y+1] < 0){
		d[x][y+1] = d[x][y] + 1; 
		dfs(x, y+1);
	}
}

int main(){
	
	memset(d, -1, sizeof(d));
	memset(m, 0, sizeof(m));
	int x2, y2, x3, y3;
	
	cin >> rows >> columns;
	
	for(int i = 1; i <= rows; i++){
		for(int j = 1; j <= columns; j++){
			cin >> m[i][j];
			
			if(m[i][j] == 3){
				x3 = i;
				y3 = j;
			}
			
			else if(m[i][j] == 2){
				x2 = i;
				y2 = j;
			}
		} 
	}
	
	d[x2][y2] = 1;
	dfs(x2, y2);
	
	cout << d[x3][y3] << endl;
	
	return 0;
}

