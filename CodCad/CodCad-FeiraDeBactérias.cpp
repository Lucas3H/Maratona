#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int n, max=0;
	int dias[50000], divisao[50000];
	
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>divisao[i]>>dias[i];
		
		if(dias[i]*log(divisao[i])>dias[max]*log(divisao[max])){
			max=i;
		}
	}
	cout<<max;
	return 0;
}
