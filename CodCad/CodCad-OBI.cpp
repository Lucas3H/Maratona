#include<iostream>

using namespace std;

int main(){
	int n, p, i, c, a, b;
	cin>>n>>p;
	i=0;
	c=0; 
	
	while(i<n){
		cin>>a>>b;
		if(a+b>=p){
			c++;
		}
		i++;
	}
	
	cout<<c;
}
