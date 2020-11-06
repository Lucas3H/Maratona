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

#define MAXN 1000000000

int main(){
	int n, c;
	int d[255][255];

	cin >> n >> c;

	frr(i, n){
		frr(j, n) d[i][j] = MAXN;
	}

	frr(i, n) d[i][i] = 0;

	int v1, v2, tam;
	frr(i, c){
		cin >> v1 >> v2 >> tam;

		d[v1][v2] = tam;
		d[v2][v1] = tam;
	}

	frr(i, n){
		frr(j, n){
			frr(k, n){
				d[j][k] = min(d[j][k], d[i][j] + d[i][k]);
				d[k][j] = d[j][k];
			}
		}
	}

	int mi = MAXN;
	frr(i, n){
		int M = 0;
		
		frr(j, n) if(M < d[i][j]) M = d[i][j];

		if(M < mi) mi = M;
	}

	cout << mi << endl;
}
