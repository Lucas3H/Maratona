#include<iostream>

using namespace std;

int main(){
	int n, k;
	cin>>n;
	int c[n+1];
	
	for(int i=1; i<=n; i++){
		cin>>c[i];
	}
	
	cin>>k;
	
	int ini=1, fim=n;
	
	while(c[ini]+c[fim]!=k){
		if(c[ini]+c[fim]>k){
			fim--;
		}
		else if(c[ini]+c[fim]<k){
			ini++;
		}
	}
	
	cout<<c[ini]<<" "<<c[fim];
	
	return 0;
}
