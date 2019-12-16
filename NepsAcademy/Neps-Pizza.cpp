#include <bits/stdc++.h>

using namespace std;

int main(){
	int fatias, a[100010], start[100010], end[100010];
	
	cin >> fatias;
	
	for(int i=0; i < fatias; i++){
		cin >> a[i];
	}
	
	int maior = 0, resp = 0;
	
	for(int i = 0; i < fatias; i++){
		maior = max(maior + a[i], 0);
		resp = max(maior, resp);
	}
	
	int s = 0;
	start[fatias] = -101;
	for(int i = fatias - 1; i >= 0; i--){ 
		s = s + a[i];
		start[i] = max(start[i+1], s);
	}
	
	int e = 0;
	end[0] = -101;
	for(int i = 1; i < fatias; i++){
		e = e + a[i-1];
		end[i] = max(end[i-1], e);
	}
	
	for(int i = 0; i < fatias; i++) resp = max(start[i] + end[i], resp);
	
	
	cout << resp << endl;
	return 0;
}
