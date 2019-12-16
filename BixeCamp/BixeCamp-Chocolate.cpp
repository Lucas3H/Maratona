#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, bar[100010];

	cin >> n;

	for(int i = 0; i < n; i++) cin >> bar[i];

	int a = 0, b = n - 1, t_a = 0, t_b = 0;

	while(a <= b){
		
		if(t_a <= t_b){
			t_a += bar[a];
			a++;
		}
		else{
			t_b += bar[b];
			b--;
		}
	
	}	

	cout << a << " " << n - 1 - b << endl;
}