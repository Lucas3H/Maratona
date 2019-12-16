#include <bits/stdc++.h>
using namespace std;


int qtossaem(int n, int p, int quemsai){
	if (p == 1 && quemsai == 1) return 0;
	if(p == 1 && quemsai == 0) return qtossaem(n, n, 1);
	if (quemsai == 0) return qtossaem(n, p-1, 1);
	int saiagora;
	if( n%2 == 0){
		saiagora = n/2;
	} else{
		saiagora = n/2 + 1;
	}
				
	if (p%2 == 0) {
		return saiagora + qtossaem(n - saiagora, p/2, (quemsai + n%2)%2);
	}
	return p/2;
}

int main(){
	long long n, m;
	long long t;
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n >> m;
		/*long long sairam = 0, saiagora, pf = m;
		while(pf%2 == 0){
			if( n%2 == 0){
				saiagora = n/2;
			}
			else{
				saiagora = n/2 + 1;
			}+
			sairam += saiagora;
			pf = pf/2;
			n = n - saiagora;
		}
		sairam += pf/2;*/
		cout << qtossaem(n, m, 1) + 1 << endl;
	}
}
