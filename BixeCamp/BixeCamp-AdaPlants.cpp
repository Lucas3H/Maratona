#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
int n, k;

int two_pointers(){
	int maior, menor;
	maior = 0;
	menor = 0;
	int max = 0;

	for(int i = 0; i < n-1; i++){
		if(v[i] <= v[i+1]){
			maior++;
			if(maior - menor > k) menor++;
		}
		else{
			menor++;
			if(menor - maior > k) maior++;
		}

		if(v[maior] - v[menor] > max) max = v[maior] - v[menor];
	}

	return max;

}

int main(){
	int test;

	cin >> test;
	for(int i = 0; i < test; i++){
		int n;
		cin >> n;

		for(int j = 0; j < n; j++){
			int a;
			cin >> a;
			v.push_back(make_pair(a, i+1));
		}

	}	
}