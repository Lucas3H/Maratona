#include<bits/stdc++.h>

using namespace std;

int mina[105][105], qtd_pedras[105][105], processado[105][105];


void Dijkstra(int X, int Y){
	qtd_pedras[X][Y] = 0;

}

int main(){
	memset(qtd_pedras, 1000000, sizeof(qtd_pedras));

	int n;
	cin >> n;

	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++) cin >> mina[105][105];
	}

	
}
