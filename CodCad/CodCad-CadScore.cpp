#include<iostream>

using namespace std;

int main(){
	int p, f, a;
	cin>>p>>f;
	
	for(int i=0;i<f;i++){
		cin>>a;
		p+=a;
		if(p<=0){
			p=0;
		}
		else if(p>=100){
			p=100;
		}
	}
	cout<<p;
}
