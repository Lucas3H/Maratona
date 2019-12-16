#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int n, m, resp=0;
	cin>>n>>m;
	
	int altura[n+1];
	
	for(int i=1; i<=n; i++){
		cin>>altura[i];
	}
	
	for(int i=1; i<=n-1; i++){
		int d;
		d=m-altura[i];
		altura[i]+=d;
		altura[i+1]+=d;
		resp+=abs(d);
	}
	
	cout<<resp<<"\n";
	
	return 0;
}
