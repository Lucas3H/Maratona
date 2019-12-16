#include<iostream>

using namespace std;

int main(){
	int n, a, b, x=1, max=1;
	cin>>n;
	cin>>a;
	for(int i=1; i<n; i++){
		cin>>b;
		
		if(a==b){
			x+=1;
			if(x>max){
				max=x;
			}
		}
		else if(a!=b){
			x=1;
		}
		
		a=b;
	}
	
	cout<<max;
	return 0;
}
