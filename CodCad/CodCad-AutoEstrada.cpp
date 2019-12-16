#include<iostream>

using namespace std;

int main(){
	int n, s=0;
	char c;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>c;
		if(c=='A'){
			s+=1;
		}
		else if(c=='P'||c=='C'){
			s+=2;
		}
		else{
		}
	}
	cout<<s;	
}
