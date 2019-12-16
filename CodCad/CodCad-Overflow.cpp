#include<iostream>

using namespace std;

int main(){
	int a, b, n;
	char c;
	cin>>n;
	cin>>a>>c>>b;
	
	if(c=='+'){
		if(a+b>n){
			cout<<"OVERFLOW";
		}
		else{
			cout<<"OK";
		}
	}
	else{
		if(a*b>n){
			cout<<"OVERFLOW";
		}
		else{
			cout<<"OK";
		}
	}
}
