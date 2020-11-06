#include<bits/stdc++.h>

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
//typedef pair<int,int> pii;
#define mk make_pair
#define pq priority_queue

#define MAXN 100010

using namespace std;

int main(){
	stack<char> v;

	int resp = 0;

	string s;
	cin >> s;

	for(int i = 0; i < s.size(); i++){
		if(v.empty()) v.push(s[i]);
		else if(v.top() == s[i]){
			resp++;
			v.pop();
		}
		else{
			v.push(s[i]);
		}
	}

	if(resp%2 == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
}
