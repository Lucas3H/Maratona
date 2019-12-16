#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	int resp = 0;
	while((m + n) > 2 && m > 0 && n > 0){
		if(n >= m){
			n-=2;
			m-=1;
			resp++;
		}
		else{
			n -= 1;
			m -= 2;
			resp++;
		}
	}
	
	cout << resp << endl;
	return 0;
}
