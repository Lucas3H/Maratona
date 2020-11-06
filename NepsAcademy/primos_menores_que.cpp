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

int main(){
	int n;
	cin >> n;
	bool primo[MAXN];
	mem(primo, 0);
	primo[1] = 1;

	frr(i, n){
		if(primo[i] == 0){
			for(int j = 2*i; j <= n; j += i){
				primo[j] = 1;
			}
		}
	}

	frr(i, n){
		if(primo[i] == 0) cout << i << " ";
	}

	cout << endl;

	return 0;
}
