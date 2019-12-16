#include<iostream>

using namespace std;

int main(){
	int n, i=1, t1=0, t2, total=0;
	cin>>n;
	cin>>t2;
	while(i<n){
		t1=t2;
		cin>>t2;
		if(t2>t1+9){
			total+=10;
		}
		else{
			total+=(t2-t1);
		}
		i++;
	}
	cout<<total+10;
}
