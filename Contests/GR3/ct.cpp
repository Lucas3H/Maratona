#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 100010

int main(){
	int n, m;
	cin >> n >> m;

	int v[10];

	frr(i, n) cin >> v[i];

	fr(i, m){
		int a, b;
		cin >> a >> b;
		swap(v[a], v[b]);
	}

	frr(i, n) cout << v[i] << " ";

}