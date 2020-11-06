#include<bits/stdc++.h>

#define frr(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int main(){
	int n;
	set<int> s;
	
	cin >> n;

	frr(i, n){
		frr(j, n){
			frr(k, n){/*
				frr(l, n){
					if(i == j || j == k || k == i || i == l || j == l || k == l) continue;
					s.insert(i + j + k + (n-3)*l);
				}*/

				if(i == j || j == k || k == i ) continue;
				int a = n/3 + 1, b = n/3;
				s.insert((n-2)*i + j + k);
			}
		}
	}

	for(auto x: s){
		cout << x << " ";
	}

	cout << endl;
	return 0;
}