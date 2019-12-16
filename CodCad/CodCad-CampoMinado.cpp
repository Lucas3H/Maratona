#include<iostream>

using namespace std;

int main(){
	int n;
	int a[52], b[52];
	cin>>n;
	a[0]=0;
	a[n+1]=0;
	
	for(int i=1; i<n+1; i++){
		cin>>a[i];
		b[i]=0;
	}
	
	for(int i=1; i<n+1; i++){
		b[i]=a[i-1]+a[i]+a[i+1];
		cout<<b[i]<<"\n";
	}
}
