#include<iostream>
using namespace std;

int hanoi(int n){
	if(n==1){
		return 1;
	}
	return 2*hanoi(n-1)+1;
}

int main(){
	int i=1;
	while(true){
		int n;
		cin>>n;
		
		if(n==0){
			break;
		}
		
		cout<<"Teste "<<i<<"\n"<<hanoi(n)<<"\n\n";
		i++;
	}
}
