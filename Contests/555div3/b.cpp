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
	int n;
	cin >> n;

	string s;
	cin >> s;

	int a[20];

	frr(i, 9) cin >> a[i];

	int resp[MAXN];

	int i = 0;
	while(true){
		if(int(s[i]) - 48 < a[int(s[i]) - 48]){
			resp[i] = a[int(s[i]) - 48];
			break;
		}
		else resp[i] = int(s[i]) - 48;
		i++;
	}

	while(int(s[i]) - 48 <= a[int(s[i]) - 48] && i < n){
		resp[i] = a[int(s[i]) - 48];
		i++;
	}
	while(i < n){
		resp[i] = int(s[i]) - 48;
		i++;
	}

	fr(j, n) cout << resp[j];
}