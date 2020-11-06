#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 100010

int main(){
	int n;
	cin >> n;

	int a, b, x, y;

	cin >> a >>x >> b>>y;

	int yes = 0;
	while(a != x && b!=y){

		if(a == b) yes = 1;

			a++;
			if(a == n+1) a = 1;
			b--;
			if(b == 0) b = n;

	}
	if(a == b) yes = 1;	

	if(yes) cout << "YES" << endl;
	else cout << "NO" << endl;
}