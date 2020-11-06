#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;
#define mk make_pair
#define pq priority_queue

#define MAXN 100010

int main(){
	int n;
	cin >> n;

	stack<int> wall;

	fr(i, n){
		int x;
		cin >> x;

		x = x%2;

		if(wall.empty()) wall.push(x);
		else{
			if(wall.top() == x) wall.pop();
			else wall.push(x);
		}
	}	

	if(wall.size() <= 1) cout << "YES" << endl;
	else cout << "NO" <<endl;

	return 0;
}
