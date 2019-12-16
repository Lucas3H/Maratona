#include<iostream>

using namespace std;

int main(){
	int x=0, y=1;
	string s;
	char vogal1[50], vogal2[50];
	
	cin>>s;
	
	for(int i=0; i<s.size(); i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
			vogal1[x]=s[i];
			x++;
		}
	}
	
	for(int i=0; i<x; i++){
		if(vogal1[i]!=vogal1[x-1-i]){
			y=0;
		}
	}
	
	if(y==0){
		cout<<"N";
	}
	else{
		cout<<"S";
	}
}
