//https://codeforces.com/contest/1204/problem/D2

#include<bits/stdc++.h>
using namespace std;
int main(){
	int cnt=0;
	string s;
	cin>>s;
	for(int i=s.size()-1;i>=0;i--)
		if(s[i]=='0')cnt++;
		else if(cnt)cnt--;
		else s[i]='0';
	cout<<s<<endl;
}
