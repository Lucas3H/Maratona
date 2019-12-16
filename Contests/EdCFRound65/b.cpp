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

#define MAXN 200010

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;

	stack<char> r, b;
	char resp[MAXN];
	fr(i, s.size()){
		if(s[i] == '('){
			if(r.size() > b.size()) {
				b.push('(');
				resp[i] = '1';			
			}
			else{
				resp[i] = '0';
				r.push('(');
			}
		}
		else{
			if(r.size() > b.size()){
				r.pop();
				resp[i] = '0';
			}

			else {
				resp[i] = '1';
				b.pop();
			}
		}
	}

	fr(i, s.size()) cout << resp[i];

	cout << endl;
}