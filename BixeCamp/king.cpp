#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 100010

int main(){
	int ix, iy, fx, fy;
	string s, q;
	cin >> s >> q;

	ix = s[0];
	iy = s[1];
	fx = q[0];
	fy = q[1];

	if(ix >= fx && iy >= fy){
		if(ix - fx > iy - fy){
			cout << ix - fx << endl;

			for(int i = 0; i < iy - fy; i++) cout << "LD\n";

			for(int i = iy - fy; i < ix - fx; i++) cout << "L\n";
		}
		else{
			cout << iy - fy << endl;

			for(int i = 0; i < ix - fx; i++) cout << "LD\n";

			for(int i = ix - fx; i < iy - fy; i++) cout << "D\n";
	
		}
	}


	else if(ix <= fx && iy <= fy){
		if(fx - ix > fy - iy){
			cout << fx - ix << endl;

			for(int i = 0; i < fy - iy; i++) cout << "RU\n";

			for(int i = fy - iy; i < fx - ix; i++) cout << "R\n";
		}
		else{
			cout << fy - iy << endl;

			for(int i = 0; i < fx - ix; i++) cout << "RU\n";

			for(int i = fx - ix; i < fy - iy; i++) cout << "U\n";
		}
	}

	else if(ix <= fx && iy >= fy){
		if(fx - ix > iy - fy){
			cout << fx - ix << endl;

			for(int i = 0; i < iy - fy; i++) cout << "RD\n";

			for(int i = iy - fy; i < fx - ix; i++) cout << "R\n";
		}
		else{
			cout << iy - fy << endl;

			for(int i = 0; i < fx - ix; i++) cout << "RD\n";

			for(int i = fx - ix; i < iy - fy; i++) cout << "D\n";
		}
	}

	else if(ix >= fx && iy <= fy){
		if(ix - fx > fy - iy){
			cout << ix - fx << endl;

			for(int i = 0; i < fy - iy; i++) cout << "LU\n";

			for(int i = fy - iy; i < ix - fx; i++) cout << "L\n";
		}
		else{
			cout << fy - iy << endl;

			for(int i = 0; i < ix - fx; i++) cout << "LU\n";

			for(int i = ix - fx; i < fy - iy; i++) cout << "U\n";
		}
	}

	return 0;
}