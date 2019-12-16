#include<iostream>
using namespace std;
int main(){
	int a, b, c, s;
	cin>>a>>b>>c;
	s=4*a+2*b+c;
	if(s==4||s==3){
		cout<<"A";
	}
	else if(s==5||s==2){
		cout<<"B";
	}
	else if(s==6||s==1){
		cout<<"C";
	}
	else{
		cout<<"*";
	}
	return 0;
}
