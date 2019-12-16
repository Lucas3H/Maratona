#include <bits/stdc++.h>

using namespace std;

int main(){
	long long f1 = 1, f2 = 1, f3;
	double F;
	for(int i = 0; i < 10; i++){
		f3 = f1 + f2;
		
		for(int j = 0; j < f3; j++) cout << "o";
		cout << endl;

		f1 = f2;
		f2 = f3;
	}
}