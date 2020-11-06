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

#define MAXN 1000010

int main(){
	int n, x;
	cin >> n >> x;

	int s[MAXN];
	fr(i, n) cin >> s[i];

	int lb = x, ub = 1;	
	int ant = s[n-1];

	frm(i, n-1){
		if(s[i] > ant && ub < s[i]){
			ub = s[i] - 1;
		}
		else if(s[i] <= ant)ant = s[i];
	}

	cout << ub << endl;

	ant = s[0];

	frr(i, n-1){
		if(s[i] < ant && lb >= s[i]){
			lb = s[i] + 1;
		}
		else if(s[i] >= ant){
			ant = s[i];
		}
	}

	cout << lb << endl;

}