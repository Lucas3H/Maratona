#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int n;
	double a[10000];
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	cout.precision(4);
	cout.setf(ios::fixed);
	for(int i=0; i<n; i++){
		cout<<sqrt(a[i])<<"\n";
	}
}
