#include<iostream>
using namespace std;
int main(){
	int cv, ce, cs, cp, fv, fe, fs, fp;
	cin>>cv>>ce>>cs>>fv>>fe>>fs;
	cp = 3*cv + ce;
	fp = 3*fv + fe;
	if(cp>fp){
		cout<<"C";
	}
	else if(cp<fp){
		cout<<"F";
	}
	else{
		if(cs>fs){
			cout<<"C";
		}
		else if(cs<fs){
			cout<<"F";
		}
		else{
			cout<<"=";
		}
	}
	return 0;
}
