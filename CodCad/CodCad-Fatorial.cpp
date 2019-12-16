#include<iostream>

using namespace std;

int fatorial(int x){
	if(x<2){
		return 1;
	}
	
	return fatorial(x-1)*x; 
}

int main(){
	int n;
	cin>>n;
	
	cout<<fatorial(n)<<endl;
}
