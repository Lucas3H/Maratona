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
	int test;
	cin >> test;

	while(test--){
		string s;
		cin >> s;

		int n = s.size();
		int a[27];
		mem(a, 0);
		//96
		
		fr(i, n){
			a[int(s[i]) - 96]++;
		}
		
		int deu = 1, seg = 0;
		frr(i, 26){
			if(a[i] != 0 && a[i-1] == 0){
				seg++;
			}
			if(a[i] > 1)deu = 0;
		}

		if(seg > 1) deu = 0;

		if(deu) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}