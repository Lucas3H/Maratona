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
#define INF 1000000000
int n, q;

int minimum[4*MAXN], pt[MAXN];

void build(int i, int l, int r){
	if(l == r) {
		minimum[i] = pt[l];
	}
	else{
		int mid  = (l+r)/2;

		build(2*i, l, mid);
		build(2*i+1, mid+1, r);

		minimum[i] = min(minimum[2*i+1], minimum[2*i]);
	}
}

int querymin(int i, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return minimum[i];
	if(ql > r || qr < l) return INF;

	int mid = (l+r)/2;

	return min(querymin(2*i, l, mid, ql, qr), querymin(2*i+1, mid+1, r, ql, qr));
}

int main(){
	int tests;
	cin >> tests;

	int j = 1;
	while(j <= tests){
		cin >> n >> q;

		frr(i, n) cin >> pt[i];

		build(1, 1, n);

		cout << "Scenario #" << j <<":"<< endl;
		fr(i, q){
			int a, b;
			cin >> a >> b;

			cout << querymin(1, 1, n, a, b) << endl;
		}
		j++;
	}
}