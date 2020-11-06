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

#define MAXN 510

int n, m;	
vector<int> adj[MAXN];
int processado[MAXN];
char s[MAXN];
vector<int> AB[3];


void dfs(int v, char c){
	processado[v] = 1;
	
	fr(i, adj[v].size()){
		int e = adj[v][i];

		if(processado[e] == -1 && adj[e].size() < n-1){
			AB[int(c) - 97].pb(e);
			dfs(e, c);
			s[e] = c;
//			cout << "v "<< v << " e " << e << " x "<<x <<endl;
		}
	}
}

int main(){
	cin >> n >> m;

	fr(i, m){
		int v1, v2;
		cin >> v1>> v2;

		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	frr(i, n){
		if(adj[i].size() == n-1) {
			s[i] = 'b';
			AB[1].pb(i);
		}
	}

	int a = -1, c = -1, x = 1;
	mem(processado, -1);
	frr(i, n){
		if(a == -1 && processado[i] == -1 && adj[i].size() < n-1){
			//cout << "a " << i << endl;
			a = adj[i].size();
			dfs(i,'a');
			s[i] = 'a';
			AB[0].pb(i);
		}
		else if(c == -1 && processado[i] == -1 && adj[i].size() < n-1){
			//cout << "c " << i << endl;
			c = adj[i].size();
			dfs(i,'c');
			s[i] = 'c';
			AB[2].pb(i);
		}
		else if(processado[i] == -1 && adj[i].size() < n-1) x = 0;
	}

	fr(i, AB[0].size()){
		if(adj[AB[0][i]].size() != AB[0].size() - 1 + AB[1].size()) x = 0;
	}

	fr(i, AB[2].size()){
		if(adj[AB[2][i]].size() != AB[2].size() - 1 + AB[1].size()) x = 0;
	}

	if(x){
		cout << "Yes" << endl;
		frr(i, n) cout << s[i];
	}
	else{
		cout<< "No" << endl;
	}
}
