#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 100010

int main(){
	int n, k;
	cin >> n >> k;

	int a = (n-k)/2 + 1;

	char resp[MAXN];

	frr(i, n){
		if(i%a == 0) resp[i] = '1';
		else resp[i] = '0';
	}

	frr(i, n) cout << resp[i];

	return 0;
}