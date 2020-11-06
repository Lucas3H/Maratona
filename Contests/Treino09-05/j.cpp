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

int n, M, t;

int main(){
	cin >> t;
	
	while(t--){
		cin >> n >> M;
		int m[MAXN][MAXN];
		pq<int> coluna1[MAXN], coluna2[MAXN];
		
		for(int i = 0; i < n; i++) {
			fr(j, M){
				cin >> m[i][j];
				coluna1[i].push(m[i][j]);
				coluna2[i].push(m[i][j]);
			}
		}

		int cont  = 0;
		frr(i, n-1){
			while(coluna1[i-1].size() > 0 && coluna2[i].size() > 0){
				if(coluna1[i-1].top() > coluna2[i].top()) coluna1[i-1].pop();
				else if(coluna1[i-1].top() < coluna2[i].top()) coluna2[i].pop();	
				else{
					cont++;
			//		cout << coluna2[i].top() << endl;

					coluna1[i-1].pop();
					coluna2[i].pop();
				}
			}
		}

		cout << cont << endl;

	}

}