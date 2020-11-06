#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, card[1010];

	int sereja = 0, dima = 0, turn = 0, ini = 0, fim;

	cin >> n;

	fim = n - 1;

	for(int i = 0; i < n; i++) cin >> card[i];

	while (turn < n){

		turn++;

		int max;

		if(card[ini] > card[fim]){
			max = ini;
			ini++;
		}
		else{
			max = fim;
			fim--;
		}

		if(turn%2 == 1){
			sereja += card[max];
		}
		else{
			dima += card[max];
		}
	}

	cout << sereja << " " << dima << endl;

	return 0;
}