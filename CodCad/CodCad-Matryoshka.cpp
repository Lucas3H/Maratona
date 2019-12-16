#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, retirar=0;
	int v[100001], a[100001], b[100001];
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>v[i];
		a[i]=v[i];
	}
	
	sort(v, v+n);
	
	for(int i=0; i<n; i++){
		if(v[i]!=a[i]){
			b[retirar]=a[i];
			retirar++;
		}
	}
	
	sort(b, b+retirar);
	
	cout<<retirar<<"\n";
	
	for(int i=0; i<retirar; i++){
		cout<<b[i]<<" ";
	}
}
