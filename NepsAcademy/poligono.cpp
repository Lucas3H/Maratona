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

int e[MAXN];
	
int main(){
	int n;
	cin >> n;

	fr(i, n) cin >> e[i];

	sort(e, e + n);

	int i = 2, max = 2;
	ll soma = e[0] + e[1];
	while(i < n){
		if(soma > e[i]) max = i+1;
		soma += e[i];
		i++;
	}

//	cout << soma << " " <<i << endl;

	if(max < 3) cout << 0 << endl;
	else cout << max << endl;

	return 0;
}