#include<iostream>
using namespace std;
int main(){
	int t1, t2, t3;
	cin>>t1;
	cin>>t2;
	cin>>t3;
	if(t1<t2 && t2<t3){
		cout<<1<<"\n"<<2<<"\n"<<3;
	}else if(t1>t2 && t2>t3){
		cout<<3<<"\n"<<2<<"\n"<<1;
	}else if(t2<t1 && t1<t3){
		cout<<2<<"\n"<<1<<"\n"<<3;
	}else if(t2>t1 && t1>t3){
		cout<<3<<"\n"<<1<<"\n"<<2;
	}else if(t1>t3 && t3>t2){
		cout<<2<<"\n"<<3<<"\n"<<1;
	}else{
		cout<<1<<"\n"<<3<<"\n"<<2;
	}
}
