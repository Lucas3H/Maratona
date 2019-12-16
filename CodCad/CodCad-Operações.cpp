#include<iostream>

using namespace std;

int main(){
	double a, b;
	char c;
	cin>>c;
	cin>>a>>b;
	if(c=='M'){
		cout.precision(2);
		cout.setf(ios::fixed);
		cout<<a*b;
	}
	else{
		cout.precision(2);
		cout.setf(ios::fixed);
		cout<<a/b;
	}
}
