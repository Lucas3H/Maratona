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

#define MAXN 110

int main(){
	int n, m1, h;

	cin >> n >> m1 >> h;

	int c[MAXN], r[MAXN], m[MAXN][MAXN];

	fr(i, m1) cin >> c[i];
	fr(i, n) cin >> r[i];

	fr(i, n){
		fr(j, m1){
			int x;
			cin >> x;

			m[i][j] = x*min(r[i], c[j]);
		}
	}

	fr(i, n){
		fr(j, m1) cout << m[i][j] << " ";
		cout << endl;
	}
}