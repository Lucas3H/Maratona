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

int mdc(int a, int b){
	if(b == 0) return a;
	return mdc(b, a%b);
}

int main(){
	int n;
	cin >> n;

	int x;
	cin >> x;
	int d = x;
	
	fr(i, n-1){
		cin >> x;
		d = mdc(d, x);
	}

	cout << d << endl;
	return 0;
}
