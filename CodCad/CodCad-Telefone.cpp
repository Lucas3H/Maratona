#include<iostream>

using namespace std;

int main(){
	string A;
	char r[16];
	cin>>A;
	for(int i=0; i<A.size(); i++){
		if(A[i]=='0'||A[i]=='1'||A[i]=='2'||A[i]=='3'||A[i]=='4'){
			r[i]=A[i];
		}
		else if(A[i]=='5'||A[i]=='6'||A[i]=='7'||A[i]=='8'||A[i]=='9'||A[i]=='-'){
			r[i]=A[i];
		}
		else if(A[i]=='A'||A[i]=='B'||A[i]=='C'){
			r[i]='2';			
		}
		else if(A[i]=='D'||A[i]=='E'||A[i]=='F'){
			r[i]='3';			
		}
		else if(A[i]=='I'||A[i]=='H'||A[i]=='G'){
			r[i]='4';			
		}
		else if(A[i]=='J'||A[i]=='K'||A[i]=='L'){
			r[i]='5';			
		}
		else if(A[i]=='O'||A[i]=='N'||A[i]=='M'){
			r[i]='6';			
		}
		else if(A[i]=='P'||A[i]=='Q'||A[i]=='R'||A[i]=='S'){
			r[i]='7';			
		}
		else if(A[i]=='U'||A[i]=='T'||A[i]=='V'){
			r[i]='8';			
		}
		else{
			r[i]='9';			
		}
	}
	
	for(int i=0; i<A.size(); i++){
		cout<<r[i];
	}
	return 0;
}
