#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 1000010

int main(){
	int n, m;
	cin >> n >> m;

	int d[110][110];

	fr(i, n){
		fr(j, n) d[i][j] = MAXN;
	}

	fr(i, m){
		int v1, v2, e;
		cin >> v1 >> v2 >> e;
		d[v1][v2] = e;
		d[v2][v1] = e;
	}

	fr(i, n) d[i][i] = 0;

	fr(i, n){
		fr(j, n){
			fr(k, n){
				d[k][j] = min(d[k][j], d[i][k] + d[i][j]);
				d[j][k] = d[k][j];
			}
		}
	}

	int mi = MAXN;
	fr(i, n){
		int M = 0;
		fr(j, n) if(d[i][j] > M) M = d[i][j];

		if(mi > M) mi = M;
	}

	cout << mi << endl;
}
