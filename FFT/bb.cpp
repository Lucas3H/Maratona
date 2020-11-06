#include<bits/stdc++.h>

using namespace std;

long long a[200010], b[200010], v[200010];
long long n;

// achar o primeiro cara >= x
long long busca_binaria(long long x, long long n) {
	long long esq=0, dir = n, meio;
	while(dir - esq > 1) {
		meio =(esq+dir)/2;
		if(v[meio] >= x) {
			dir = meio;
		}
		else if(v[meio] < x){
			esq = meio;
		}
	}
	
	return dir;
}

int main(){
	long long n;
	scanf("%lld", &n);

	for(long long i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	for(long long i = 0; i < n; i++){
		scanf("%lld", &b[i]);
		v[i] = a[i] - b[i];
	}

	sort(v, v + n);

	long long ans = 0;
	for(long long i = 0; i < n; i++){
		if(v[i] <= 0){
			ans += (n - busca_binaria(-v[i] + 1, n)); 
		}
		else{
			ans += n - i - 1;
		}
	}

	printf("%lld\n", ans);
}