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

#define MAXN 1010

int main(){
	int n;
	cin >> n;
	int x1, y1, x2, y2;
	int insensibilidade = 0;

	fr(i, n){
		cin >> x1 >> y1 >> x2 >> y2;

		insensibilidade += (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	}

	cout << insensibilidade << endl;

	return 0;
}
