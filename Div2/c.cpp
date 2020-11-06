#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

int main(){
	int n;
	cin >> n;

	int um = 0, dois = 0;

	fr(i, n){
		int x;
		cin >> x;
		if(x == 1) um++;
		else dois++;
	}

	if(um == 0){
		fr(i, n) cout << 2 << " ";	
	}
	else if(dois == 0){
		fr(i, n) cout << 1 << " ";
	}	
	else{
		cout << 2 << ' ' << 1 << ' ';
		for(int i = 0; i < dois - 1; i++) cout << 2  << ' ';
		for(int i = 0; i < um - 1; i++) cout << 1 << ' ';
	}
	
	cout << endl;
}
