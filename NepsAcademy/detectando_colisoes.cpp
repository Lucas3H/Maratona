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
	int x[4], y[4];
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	cin >> x[2] >> y[2] >> x[3] >> y[3];

	if(x[0] > x[1]) swap(x[0], x[1]);
	if(y[0] > y[1]) swap(y[0], y[1]);
	if(x[2] > x[3]) swap(x[2], x[3]);
	if(y[2] > y[3]) swap(y[2], y[3]);

	if( x[0] > x[3] || y[0] > y[3] || x[2] > x[1] || y[2] > y[1]) cout << 0 << endl;
	else cout << 1 << endl;

	return 0;
}
