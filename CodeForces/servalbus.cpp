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

#define MAXN 1000000010

int main(){
	int n, t;
	cin >> n >> t;

	int d, s;

	int first = 0, r = MAXN;
	fr(i, n) {
		cin >> s >> d;

		int k;
		if(s >= t) k = s;
		else{
			int q;
			if((t-s)%d == 0) q = (t-s)/d;
			else q = (t-s)/d + 1;

			k = s + d*q;
		}

		if(k < r){
			first = i;
			r = k;
		}
	}

	cout << first +1 << endl;

}