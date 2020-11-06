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

#define MAXN 1300010
bool eh_composto[MAXN];
int primo[MAXN];

int main(){	
	int q, primos = 1;
	cin >> q;

	mem(eh_composto, 0);

	for(int i = 2; i < MAXN ;i++){
		if(!eh_composto[i]){
			primo[i] = primos;
			primos++;

			for(int j = 2; j*i < MAXN; j++){
				eh_composto[i*j] = 1;
			}
		}
	}

	int p;
	fr(i, q){
		cin >> p;

		cout << primo[p] << endl;
	}

	return 0;
}
