#include<iostream>

using namespace std;

int main(){
	char n, a[101];
	string C;
	while(true){
		
		cin>>n>>C;
		if(n=='0' && C=="0"){
			break;
		}
		
		int x=0;
		for(int i=0; i<C.size(); i++){
			if(C[i]!=n){
				a[x]=C[i];
				x++;
			}
		}
		a[x]='1';
		
		int y=0;
		while(a[y]=='0'){
			y++;
		}
		
		if(y==x){
			cout<<"0";
		}
		else{
			for(int i=y; i<x; i++){
				cout<<a[i];
			}
		}
		
		cout<<"\n";
	}
	
	
}
