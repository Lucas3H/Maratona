#include <bits/stdc++.h>

using namespace std;

int main(){
	char m[1002][1002];
	
	int rows, columns;
	
	cin >> rows >> columns;
	
	for(int i = 1; i <= rows; i++){
		for(int j = 1; j <= columns; j++) cin >> m[i][j];
	}
	
	for(int i = 1; i <= rows; i++){
		m[i][0] = '.';
		m[i][columns+1] = '.';	
	}
	for(int i = 1; i <= columns; i++){
		m[0][i] = '.';
		m[rows+1][i] = '.';	
	}
	
	int coast = 0;
	
	for(int i = 1; i <= rows; i++){
		for(int j = 1; j <= columns; j++){
			if(m[i][j] == '#' && (m[i-1][j] == '.' || m[i+1][j] == '.' || m[i][j-1] == '.' || m[i][j+1] == '.')) coast++;
		}
	}
	
	cout << coast << endl;
	
	return 0;
}
