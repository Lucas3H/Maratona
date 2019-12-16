#include<iostream>
using namespace std;
int main(){
	double n1, n2, n3, n4, n5, maior, menor;
	cin>>n1>>n2>>n3>>n4>>n5;
	if(n1>n2){
		maior = n1;
		menor = n2;
	}
	else{
		maior = n2;
		menor = n1;
	}
	if(n3>maior){
		maior = n3;
	}
	if(n3<menor){
		menor = n3;
	}
	if(n4>maior){
		maior = n4;
	}
	if(n4<menor){
		menor = n4;
	}
	if(n5>maior){
		maior = n5;
	}
	if(n5<menor){
		menor = n5;
	}
	cout.precision(1);
	cout.setf(ios::fixed);
	cout<<n1+n2+n3+n4+n5-maior-menor;
}
