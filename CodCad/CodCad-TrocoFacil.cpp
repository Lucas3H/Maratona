#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int n, resposta=0;
	cin>>n;
	
	resposta+=floor(n/100);
	n=n%100;
	
	resposta+=floor(n/50);
	n=n%50;
	
	resposta+=floor(n/25);
	n=n%25;
	
	resposta+=floor(n/10);
	n=n%10;
	
	resposta+=floor(n/5);
	n=n%5;
	
	resposta+=n;
	
	cout<<resposta;
}
