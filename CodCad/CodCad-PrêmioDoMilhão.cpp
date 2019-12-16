#include<iostream>

using namespace std;

int main(){
	int n, i=0, a, s=0, dias=0;
	cin>>n;
	
	while(i<n){
		cin>>a;
		s = s + a;
		i++;
		if(s<1000000){
			dias++;
		}
	}
	cout<<dias+1;
}
