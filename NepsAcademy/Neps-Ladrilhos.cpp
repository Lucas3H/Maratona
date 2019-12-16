#include <bits/stdc++.h>

using namespace std;

int rows, columns;
int l[205][205], visto[205][205], component[40010], c = 0;

void dfs(int x, int y){
	if(x >= 1 && x <= rows && y >= 1 && y <= columns){
		visto[x][y] = 0;
		
		if(l[x][y] == l[x-1][y] && visto[x-1][y] == -1){
			component[c]++;
			dfs(x-1, y);
		}
		if(l[x][y] == l[x+1][y] && visto[x+1][y] == -1){
			component[c]++;
			dfs(x+1, y);
		
		}
		if(l[x][y] == l[x][y-1] && visto[x][y-1] == -1){
			component[c]++;
			dfs(x, y-1);
		}
		if(l[x][y] == l[x][y+1] && visto[x][y+1] == -1){
			component[c]++;
			dfs(x, y+1);
		}
	}
}

int main(){
	
	cin >> rows >> columns;
	
	memset( visto, -1, sizeof(visto));
	
	for(int i = 0; i < 40010; i++) component[i] = 1;
	
	for(int i = 1; i <= rows; i++){
		for(int j = 1; j <= columns; j++) cin >> l[i][j];
	}
	
	for(int i = 1 ; i <= rows; i++) l[i][0] = l[i][columns+1] = -1;
	for(int i = 1 ; i <= columns; i++) l[0][i] = l[rows+1][i] = -1;
	
	for(int i = 1; i <= rows; i++){
		for(int j = 1; j <= columns; j++){
			if(visto[i][j] == -1){
				c++;
				dfs(i, j);
			}
		}
	}
	
	int min = 40010;
	
	for(int i = 1; i <= c; i++){
		if(min > component[i]) min = component[i];
	}
	
	cout << min << endl;
	
	return 0;
}
