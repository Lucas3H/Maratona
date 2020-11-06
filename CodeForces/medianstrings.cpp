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

#define MAXN 200010

int main(){
	int k;
	cin >> k;
	string s, t;
	cin >> s >> t;

	int a[MAXN], b[MAXN], resp[MAXN];

	fr(i, k){
		a[i] = int(s[i]) - 97;
		b[i] = int(t[i]) - 97;
	}

	resp[k-1] = (a[k-1] + b[k-1])/2;

	for(int i = k-2;i>=0; i--){
		int x = (a[i] + b[i])*13;

		int r = x%26, q = x/26;

		resp[i+1] += r;
		resp[i] = q;

		if(resp[i+1] >= 26){
			resp[i+1]-=26;
			resp[i]++;
		}
	}

	fr(i, k) cout << char(resp[i] + 97);
}