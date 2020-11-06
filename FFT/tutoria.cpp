#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, l;
	int a[1010];
	scanf("%d %d", &n, &l);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	sort(a, a + n);
	
	int maior = 0;
	for(int i = 0; i < n-1; i++){
		if(a[i + 1] - a[i] > maior){
			maior = a[i+1] - a[i];
		}
	}

	if(2*a[0] > maior){
		maior = 2*a[0];
	}

	if(2*(l - a[n-1]) > maior){
		maior = 2*(l - a[n-1]);
	}

	printf("%lf\n", (double)maior/2);
}