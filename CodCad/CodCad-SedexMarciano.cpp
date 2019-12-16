#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int l, a, p, r;
	cin>>l>>a>>p>>r;
	
	if(sqrt(l*l+a*a+p*p)>2*r){
		cout<<"N";
	}
	else{
		cout<<"S";
	}
}
