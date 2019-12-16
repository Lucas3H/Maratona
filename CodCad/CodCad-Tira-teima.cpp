#include<iostream>
using namespace std;
int main(){
	int x, y;
	cin >> x >> y;
	if(x<=432 && x>=0 && y>=0 && y<=468){
		cout<<"dentro";
	}
	else{
		cout<<"fora";
	}
	return 0;
}
