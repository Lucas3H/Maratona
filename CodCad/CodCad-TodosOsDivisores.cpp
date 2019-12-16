#include<iostream>

using namespace std;

int main(){
	int n, i;
	i=1;
	cin>>n;
	while(i<n+1){
		if(n%i==0){
			cout<<i<<" ";
		}
		i++;
	}
}
