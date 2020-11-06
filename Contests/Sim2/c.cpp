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
	int n;
	cin >> n;
	string s;
	cin >> s;

	stack<char> a;

	fr(i, n){
		if(a.size()%2 == 0) a.push(s[i]);
		else{
			if(a.top() == s[i]) continue;
			else{
				a.push(s[i]);
			}
		}
	}

	if(a.size()%2 == 1) a.pop();
	cout << n - a.size() << endl;
	vector<char> resp;
	int k = a.size();

	fr(i, k){
		resp.pb(a.top());
		a.pop();
	}

	for(int i = k-1; i >=0 ; i--) cout << resp[i];
}