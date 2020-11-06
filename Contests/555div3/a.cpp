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
	int n;
	cin >> n;

	int resp = 0;
	while(n > 9){
		
		int r = n%10;

		resp += 10 - r;

		n += 10-r;

		while(n%10 == 0){
			n /= 10;
		}
	}

	resp += 9;
		
	cout << resp << endl;	
}	