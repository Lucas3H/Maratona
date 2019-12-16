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

#define MAXN 100010

int n, f, r;
int pai[110], peso[110];

int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y){
	int a = find(x), b = find(y);

	if(a == b) return;
	else if(peso[a] > peso[b]) pai[b] = a;
	else if(peso[a] < peso[b]) pai[a] = b;
	else{
		pai[a] = b;
		peso[b]++;
	}
}

int main(){
	cin >> n >> f >> r;

	frr(i, n){
		pai[i] = i;
		peso[i] = 1;
	}

	pq<tuple<int, int, int>> ferrovias, rodovias;

	int v1, v2, c;	
	fr(i, f){
		cin >> v1 >> v2 >> c;
		ferrovias.push(make_tuple(-c, v1, v2));
	}

	fr(i, r){
		cin >> v1 >> v2 >> c;
		rodovias.push(make_tuple(-c, v1, v2));
	}

	int cost = 0;
	fr(i, f){
		int e;
		tie(e, v1, v2) = ferrovias.top();
		ferrovias.pop();

		if(find(v1) != find(v2)){
			join(v1, v2);
			cost -= e;
		} 
	}

	fr(i, r){
		int e;
		tie(e, v1, v2) = rodovias.top();
		rodovias.pop();

		if(find(v1) != find(v2)){
			join(v1, v2);
			cost -= e;
		} 
	}

	cout << cost << endl;

	return 0;	
}
n