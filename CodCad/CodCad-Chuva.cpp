#include<iostream>

using namespace std;

int main(){
	int n;
	int a[100][100], b[100][100];
	cin>>n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>b[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<a[i][j]+b[i][j]<<" ";
		}
		cout<<"\n";
	}
}
