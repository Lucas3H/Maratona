#include<iostream>

using namespace std;

int main(){
	int h,p,f,d;
	
	cin >> h >> p >> f >> d;

	if(d==1){
		if((h>p && p>f)||(f>h && h>p)||(p>f && f>h)){
			cout << "N" << endl;
		}else{
			cout << "S" << endl;
		}
	}
	else{
		if((h>p && p>f)||(f>h && h>p)||(p>f && f>h)){
			cout<< "S" << endl;
		}
		else{
			cout<< "N" << endl;
		}
	}
}
