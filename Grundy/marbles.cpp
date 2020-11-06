// https://codeforces.com/gym/101908/problem/B
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int m[102][102];

int mex(int l, int c){
	if(m[l][c] != -1) return m[l][c];
	if(l == 2 && c == 1) return 0;
	if(l == 1 && c == 2) return 0;

	set<int> me;
	frr(i, l-1) me.insert(mex(i, c));
	frr(i, c-1) me.insert(mex(l, i)); 
	frr(i, min(l, c) - 1) me.insert(mex(l - i, c - i));

	int it = 0;
	while(me.find(it) != me.end()) it++;

	return m[l][c] = it;
}

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	mem(m, -1);

	frr(i, 100){
		m[i][i] = MAXN;
	}

	int l, c;
	int deu = 0, sum = 0;
	fr(i, n){
		cin >> l >> c;

		if(l == c) deu = 1;
		else sum^=mex(l, c);
	}/*
	frr(i, 10){
		frr(j, 10) cout << mex(i, j) << " ";
		cout << endl;
	}*/

	if(deu) cout << "Y\n";
	else{
		if(sum == 0) cout << "N\n";
		else cout << "Y\n";
	}
}
