#include<iostream>
#include <algorithm>
using namespace std;

int main(){
	cout.precision(9);
	
	int n;
	double l;
	double c[1010];
	
	cin >> n >> l;
	
	for(int i=0; i < n; i++){
		cin >> c[i];
		c[i] = c[i];
	}
	
	
	sort(c, c+n);
	double max = 2*c[0];
	
	for(int i=0; i < n-1; i++){
		if(c[i+1]-c[i] > max){
			max = c[i+1]-c[i];	
		} 
	}
	
	if(max < 2*l - 2*c[n-1]) 
	{
		max = 2*l - 2*c[n-1];	
	}
	
	double m=max/2;
	
	cout << m << endl;
	
	return 0;
}
