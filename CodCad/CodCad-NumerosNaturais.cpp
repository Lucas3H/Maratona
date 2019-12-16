#include<iostream>

using namespace std;

int somaate(int n){
	if(n==1){
		return 1;
	}
	return somaate(n-1)+n;
}

int main(){
	int n;
	cin>>n;
	
	cout<<somaate(n);
}
