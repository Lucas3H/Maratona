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

#define MAXN 10010

int pai[MAXN];

int main(){
	int n;
	cin >> n;

	frr(i, n){
		int x;
		cin >> x;
		pai[i] = x;
	}

	int resp = 0, max = 0;
	frr(i, n){
		if(max < pai[i]) max = pai[i];
		
		if(max == i){
			resp++;
			max = pai[i+1];
		}
	}

	cout << resp << endl;
}