#include <bits/stdc++.h>
#define INF 1000000001

using namespace std;

vector<int> V;
	
int n;

void merge_sort(vector<int> &v){
	if(v.size() == 1) return;
	
	vector<int> u1, u2;
	
	for(int i=0; i<v.size()/2; i++) u1.push_back(v[i]);
	for(int i=v.size()/2; i<v.size(); i++) u2.push_back(v[i]);
	
	merge_sort(u1);
	merge_sort(u2);
	
	u1.push_back(INF);
	u2.push_back(INF);
	
	int ini1 = 0, ini2 = 0;
	
	for(int i=0; i<v.size(); i++){
		if(u1[ini1] > u2[ini2]) {
			v[i] = u2[ini2];
			ini2++;
		}
		else {
			v[i] = u1[ini1];
			ini1++;
		}
	}
	
	return;
}

int main(){
	cin >> n;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		V.push_back(x);
	}
	
	merge_sort(V);
	
	for(int i=n-1; i>=0; i--) cout << V[i] << " ";
}
