#include<iostream>
using namespace std;

int x=0;

int funcao(int n){
	if(n==1){
		return x;
	}
	else if(n%2==0){
		x++;
		return funcao(n/2);
	}
	x++;
	return funcao(n*3+1);
}

int main(){
	int n;
	cin>>n;
	cout<<funcao(n);
}
