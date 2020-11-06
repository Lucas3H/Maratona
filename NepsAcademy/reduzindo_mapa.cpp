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

#define MAXN 100010

int pai[510], peso[510];

int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y){
	int a = find(x), b = find(y);

	if(a == b) return;

	if(peso[a] > peso[b]){
		pai[b] = a;
	}
	else if(peso[a] < peso[b]){
		pai[a] = b;
	}
	else{
		pai[a] = b;
		peso[b]++;
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	int u, v, c;

	frr(i, n){
		pai[i] = i;
		peso[i] = 1;
	}

	pq<tuple<int, int, int>> edges;

	fr(i, m){
		cin >> u >> v >> c;

		edges.push(make_tuple(-c, u, v));
	}

	ll sum = 0, k = 0;
	fr(i, m){
		int e, v1, v2;
		tie(e, v1, v2) = edges.top();

		if(find(v1) != find(v2)){
			join(v1, v2);
			sum += -e;

			k++;
        }

		edges.pop();
	}

	cout << sum << endl;

	return 0;
}
