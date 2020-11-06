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

vector<int> ans;
void recover(int ind, int cap){
	if(ind == n) return;

	int pega = value[ind] + pd(ind+1, cap - wght[ind]);
	int passa = pd(ind+1, cap);

	if(pega > passa){
		ans.pb(ind);
		recover(ind+1, cap - wght[ind]);
	}
	else{
		recover(ind+1, cap);
	}
}

int main(){
}