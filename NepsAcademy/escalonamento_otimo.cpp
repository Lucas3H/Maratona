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

int grau[50010];
vector<int> out[50010];

int main(){
	int n, m;

	cin >> n >> m;

	mem(grau, 0);
	fr(i, m){
		int v1, v2;
		cin >> v1 >> v2;

		out[v1].pb(v2);
		grau[v2]++;
	}

	pq<int, vector<int>, greater<int>> in_0;	

	fr(i, n){
		if(grau[i] == 0) in_0.push(i);
	}

	vector<int> ordem;

	while(!in_0.empty()){
		int davez = in_0.top();
		in_0.pop();
		ordem.pb(davez);

		for(int i = 0; i < out[davez].size(); i++){
			grau[out[davez][i]]--;
			if(grau[out[davez][i]] == 0) in_0.push(out[davez][i]);
		}
	}

	if(ordem.size() < n) cout << '*' << endl;
	else{
		fr(i, n) cout << ordem[i] << endl;
	}
}
