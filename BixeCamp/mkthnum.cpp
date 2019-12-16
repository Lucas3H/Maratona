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
pq<int, vector<int>, greater<int>> s[4*MAXN];
int v[MAXN];

void build(int i, int l, int r){
	if(l == r) s[i].push(v[l]);
	else{
		int mid = (l+r)/2;

		build(2*i, l, mid);
		build(2*i+1, mid+1, r);

		s[i] = s[2*i];
		pq<int, vector<int>, greater<int>> aux = s[2*i+1];

		while(!aux.empty()){
			s[i].push(aux.top());
			aux.pop();
		}
	}
}

pq<int> query(int i, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr){
		pq<int, vector<int>, greater<int>> resp = s[i];
		while(resp.size() > k) resp.pop(); 
		return resp;
	}
	if(ql > r || l > qr){
		pq<int> S;
		return S;
	}

	int mid = (l+r)/2;

	pq<int, vector<int>, greater<int>> s1 = query(2*i, l, mid, ql, qr), s2 = query(2*i+1, mid+1, r, ql, qr);

	pq<int, vector<int>, greater<int>> S;

	while()

	if(s1.top())


	return s1;
}

int main(){
	int n, m;
	cin >> n >> m;

	frr(i, n) cin >> v[i];

	build(1, 1, n);

	fr(i, m){
		int a, b, c;
		cin >> a >> b >> c;

		set<int> resp = query(1, 1, n, a, b);

		for(auto x: resp){
			if(c==1){
				cout << x << endl;
				break;
			}
			c--;
		}
	}
}