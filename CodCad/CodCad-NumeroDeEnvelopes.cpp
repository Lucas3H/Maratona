#include<iostream>

using namespace std;

int main(){
	int n, b, min;
	cin>>n;
	cin>>b;
	min=b;
	
	for(int i=1; i<n; i++){
		cin>>b;
		if(b<min){
			min=b;
		}
	}
	cout<<min;
}
