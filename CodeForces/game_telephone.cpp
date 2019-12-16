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

int main(){
	int n;
	string s;
	cin >> n >> s;
	int oitos = 0;

	fr(i, n - 10){
		if(s[i] == '8') oitos++;
	}

	if(oitos > (n - 10)/2) cout << "YES" << endl;
	else cout << "NO" <<endl;	
}
