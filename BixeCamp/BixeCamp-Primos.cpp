#include<iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    
    if(n==1) cout << "N" << endl;
    else if(n==2) cout << "S" << endl;
    else if(n==3) cout << "S" << endl;
    else{
    	bool x = 1;
    	
		if(n%2==0) x= 0;    
    	else{
        	for (int i=3; i*i<n; i+=2){
        		if(n%i==0){
        			x=0;
        			break;
				}
        	}
		}
    
        if(x) cout << "S" << endl;
        else cout << "N" << endl;
    }
    
    return 0;
}
