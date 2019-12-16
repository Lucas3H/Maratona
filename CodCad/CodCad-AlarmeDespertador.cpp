#include<iostream>

using namespace std;

int main(){
	
	int h1, m1, t1, h2, m2, t2;
	
	cin>>h1>>m1>>h2>>m2;
	
	while(h1+m1+h2+m2!=0){
	
		t1 = h1*60 + m1;
		t2 = h2*60 + m2;
	
		if(t2-t1>0){
			cout<<t2-t1<<"\n";
		}
		else{
			cout<<1440+t2-t1<<"\n";
		}
		cin>>h1>>m1>>h2>>m2;
	}
}
