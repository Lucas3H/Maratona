#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, v[5];
	cin>>n;
	for(int i=1; i<4; i++){
		cin>>v[i];
	}
	v[4]=1000;
	
	sort(v+1, v+4);
	
	int qtd=0, s=0;
	while(true){
		qtd++;
		s+=v[qtd];
		if(s>n){
			qtd--;
			break;
		}
	}
	
	cout<<qtd;
}
