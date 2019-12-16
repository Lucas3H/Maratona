#include<iostream>

using namespace std;

int main(){
	int n, s=0, x=0;
	int a[100000];
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>a[i];
		s+=a[i];
	}
	
	for(int i=0; i<n; i++){
		x+=a[i];
		if(x==s/2){
			x=i;
			break;
		}
	}
	cout<<x+1;
	return 0;
}
