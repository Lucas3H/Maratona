#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

int inv(vector<int> &v){
	if(v.size()==1) return 0;
	
	vector<int> u1, u2;
	
	for(int i=0; i<v.size()/2; i++) u1.push_back(v[i]);
	for(int i=v.size()/2; i<v.size(); i++) u2.push_back(v[i]);
	
	int resp = inv(u1) + inv(u2);
	
	u1.push_back(INF);
	u2.push_back(INF);
	
	int ini1 = 0, ini2 = 0;
	
	for(int i=0; i<v.size(); i++){
        if(u2[ini2]<u1[ini1]){
            v[i]=u2[ini2];
            ini2++;
            resp+=u1.size()-ini1-1;
        }
        else{
            v[i]=u1[ini1];
            ini1++;
        }
    }
	
	return resp;
}

int main(){
	int n;
	vector<int> V;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		V.push_back(x);
	}
	
	cout << inv(V) << endl;
	
	return 0;
}
