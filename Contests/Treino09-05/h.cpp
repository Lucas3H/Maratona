#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) z
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

	while(n--){
		string s;
		cin >> s;

		int deu = 1;
		for(int i = 1; i < s.size(); i++){
			if(int(s[i])%26 != (int(s[i-1]) + 1)%26){
				deu = 0;
				break;
			} 
		}

		if(deu) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}