#include<iostream>

using namespace std;

int main(){
	int n, s, i=0, min, m;
	cin>>n>>s;
	min = s;
	
	while(i<n){
		cin>>m;
		s = s + m;
		if(s<min){
			min = s;
		}
		i++;
	}
	
	cout<<min;
	return 0;
}
