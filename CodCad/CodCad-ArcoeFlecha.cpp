#include <bits/stdc++.h>

using namespace std;

long long inv(vector<long long> &v){
	if(v.size()==1) return 0;
	
	vector<long long> u1, u2;
	
	for(int i=0; i<v.size()/2; i++) u1.push_back(v[i]);
	for(int i=v.size()/2; i<v.size(); i++) u2.push_back(v[i]);
	
	long long resp = inv(u1) + inv(u2);
	
	u1.push_back(-1);
	u2.push_back(-1);
	
	int i1=0, i2=0;
	
	for(int i=0; i<v.size(); i++){
		if(u1[i1] > u2[i2]){
			v[i] = u1[i1];
			i1++;
		}
		else{
			v[i] = u2[i2];
			i2++;
			resp+=u1.size()-i1-1; 
		}
	}
	
	return resp;
}

int main(){
	int n;
	vector<long long> V;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		long long a, b;
		cin >> a >> b;
		
		V.push_back(a*a+b*b);
	}
	
	cout << inv(V) << endl;
	
	return 0;
}
