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
//#define INF 100000000000001

int n;
string s[MAXN];
int value[MAXN];
ll memo[MAXN][2];
ll INF = 1;
int resp = 1;

ll dp(int ind, int rev){
	if(ind == n + 1) return 0;

	if(memo[ind][rev] != -1) return memo[ind][rev];

	ll revert = INF;
	ll wn_rev = INF;

	if(rev == 0){

		int pref = 1;
		for(int i = 0; i < s[ind-1].size(); i++){
			if(i==s[ind].size()){
				pref = 0;
				break;
			}

			if(s[ind-1][i] > s[ind][i]){
				pref = 0;
				break;
			}
			else if(s[ind - 1][i] < s[ind][i]){
				pref = 0;
				wn_rev = dp(ind+1, 0);
				break;
			}

		}

		if(pref) wn_rev = dp(ind+1, 0);
		
		pref = 1;
		int k = s[ind].size()-1;
		for(int i = 0; i < s[ind-1].size(); i++){
			if(k-i == -1){
				pref = 0;
				break;
			}

			if(s[ind-1][i] > s[ind][k-i]){
				pref = 0;
				break;
			}
			else if(s[ind - 1][i] < s[ind][k-i]){
				pref = 0;
				revert = dp(ind+1, 1) + value[ind];
				break;
			}
		}

		if(pref) revert = dp(ind+1, 1) + value[ind];
	}
	else{

		int l = s[ind-1].size();
		int pref = 1;

		frm(i, l){
			if(l-1-i == s[ind].size()){
				pref = 0;
				break;
			}

			if(s[ind-1][i] > s[ind][l-1-i]) {
				pref = 0;
				break;
			}
			else if(s[ind - 1][i] < s[ind][l-1-i]){
				pref = 0;
				wn_rev = dp(ind+1, 0);
				break;
			}
		}

		if(pref) wn_rev = dp(ind+1, 0);

		int k = s[ind].size();
		pref = 1;

		frm(i, l){
			if(k-l+i == -1){
				pref = 0;
				break;
			}

			if(s[ind-1][i] > s[ind][k-l+i]){
				pref = 0;
				break;
			}
			else if(s[ind-1][i] < s[ind][k-l+i]){
				pref = 0;
				revert = dp(ind+1, 1) + value[ind];
				break;
			}
		}
			

		if(pref) revert = dp(ind+1, 1) + value[ind];	
	}

	return memo[ind][rev] = min(wn_rev, revert);
}

int main(){
	cin >> n;

	frr(i, n) {
		cin >> value[i];
		INF += value[i];
	}

	s[0] = "0";
	frr(i, n){
		cin >> s[i];
	}

	mem(memo, -1);

	ll d = dp(1, 0);
		
	if(d < INF){
		cout << d << endl;
	}
	else cout << -1 << endl;

	return 0;
}