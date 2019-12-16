#include<iostream>
using namespace std;
int main(){
	double a,b;
	cin>>a>>b;
	if((a+b)/2<4){
		cout<<"Reprovado";
	}
	else if((a+b)/2<7){
		cout<<"Recuperacao";
	}
	else{
		cout<<"Aprovado";
	}
	return 0;
}
