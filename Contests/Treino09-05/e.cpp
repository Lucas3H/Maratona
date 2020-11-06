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
	int t;
	cin >> t;

//	cout << int('0') << " " << int('a') << endl;

	while(t--){
		int n, m;
		cin >> n >> m;

		int price[26];

		fr(i, 26) price[i] = 10;

		string s, p;
		cin >> s >> p;

//		fr(i, n) cout << price[i] << " ";


		fr(i, n){
			if(int(p[i]) - 48 < price[int(s[i]) - 97]) price[int(s[i]) - 97] = int(p[i]) - 48;
		}

		string q;
		cin >> q;

		int cost = 0;
		fr(i, m){
			if(price[int(q[i]) - 97] == 10){
				cost = -1;
				break;
			}
			cost += price[int(q[i]) - 97];
		}	
		cout << cost << endl;
	}
}