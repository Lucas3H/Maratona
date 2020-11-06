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

	string s;
	while(t--){
		cin >> s;

		int i = 0, n = 0, k = 0;
		stack<int> num;
		while(i < s.size()){
			if(s[i] != '!')num.push(int(s[i]) - 48);
			else k++;

			i++;
		}

		int dez = 1;
		while(num.size() > 0){
			n += num.top()*dez;
			dez *= 10;
			num.pop();
		}

		ll resp = n, termo = n - k;

		while(termo > 0){
			resp *= termo;
			termo -= k;
		}

		cout << resp << endl;
	}

	return 0;
}