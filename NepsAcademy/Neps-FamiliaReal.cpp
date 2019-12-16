#include <bits/stdc++.h>

using namespace std;

vector<int> d[10010];
int g[10010], G[10010], GP[10010];

void dfs(int n, int gen){
	g[n] = gen;
	G[gen]++;
	for(int i = 0; i < d[n].size(); i++){
		dfs(d[n][i], gen+1);
	}
}

int main(){
	int desc, p;
	cin >> desc >> p;
	
	memset( G, 0, sizeof(G));
	memset( GP, 0, sizeof(GP));
	
	for(int i = 1; i <= desc; i++){
		int x;
		cin >> x;
		d[x].push_back(i);
	}
	
	dfs(0, 0);
	
	int maior = 0;
	for(int i = 1; i <= desc; i++){
		if(maior < g[i]) maior = g[i];
	}
	
	for(int i = 1; i <= p; i++){
		int x;
		cin >> x;
		GP[g[x]]++;
	}
	
	cout.precision(2);
	cout.setf(ios::fixed);
	
	for(int i = 1; i <= maior; i++){
		double x = GP[i]*100;
		
		cout << x/G[i] << " ";
	}
	
	return 0;
}
