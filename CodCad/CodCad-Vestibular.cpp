#include<iostream>

using namespace std;

int main(){
	int n, acertos=0;
	string A, B;
	
	cin>>n;
	cin>>A;
	cin>>B;
	
	for(int i=0; i<n; i++){
		if(A[i]==B[i]){
			acertos++;
		}
	}
	
	cout<<acertos;
}
