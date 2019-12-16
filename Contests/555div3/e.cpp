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

#define MAXN 200010

int main(){
	int n;
	cin >> n;

	int a[MAXN];
	multiset<int> b;

	fr(i, n) cin >> a[i];

	fr(i, n) {
		int x;
		cin >> x;
		b.insert(x);
	}

	int resp[MAXN];

	fr(i, n){
		auto it = b.lower_bound(n - a[i]);

		if(it == b.end()) it = b.begin();

		resp[i] = (*it);
		b.erase(it);

		a[i] = (a[i]+ resp[i])%n;
		
	}

	fr(i, n) cout << a[i] << " ";


}