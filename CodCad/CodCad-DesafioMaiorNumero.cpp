#include<iostream>

using namespace std;

int main(){
	int a, m;
	cin>>a;
	m=a;
	
	while(a!=0){
		cin>>a;
		if(m<a){
			m=a;
		}
	}
	cout<<m;
}
