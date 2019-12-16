#include <bits/stdc++.h>

using namespace std;

int a[100005];
int n, k;

int bb(long long x){
	if(x > a[n-1]) return 0;
	
	int ini = 0, fim = n-1, meio;
	
	while(ini <= fim){
		meio = (ini+fim)/2;
		
		if(a[meio] == x) return meio;
		else if(a[meio] > x) fim = meio;
		else if(a[meio+1] <= x) ini = meio+1;
		else return 0;
	}
	
	return 0;	
}

int main (){
	int b[100005];
	
	cin >> n >> k;
	
	for(int i=0; i<n; i++){
		cin >> a[i];
		b[i] = 0;	
	}
	
	sort(a, a+n);
	
	int resp=0;
	
	for(int i=0; i<n; i++){
		if(b[i]==0){
			resp++;
			b[bb(a[i]*k)] = 1;
		}
	}
	
	cout << resp << endl;
	
	return 0;
}
