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
	int n;
	cin >> n;

	int quotes = 0, open = 0, close = 0;
	string s;
	cin >> s;

	fr(i, n){
		if(s[i] == '?') quotes++;
		else if(s[i] == '(') open++;
		else close++;
	}

	if(n%2 == 1 || open > n/2 || close > n/2){
		cout << ":(" << endl;
		return 0;
	}

	int qo = n/2 - open, qc = n/2 - close;

	int deu = 1;
	stack<char> p;
	vector<char> v;
	fr(i, n){
		if(s[i] == '('){
			p.push('(');
			v.pb('(');
			continue;
		}
		else if(s[i] == ')'){
			if(p.empty()){
				deu = 0;
				break;
			}
			else{
				p.pop();
				v.pb(')');
			}
		}
		else{
			if(qo > 0) {
				p.push('(');
				v.pb('(');
				qo--;
			}
			else{
				p.pop();
				v.pb(')');
				qc--;
			}
		}

		if(p.empty() && i <n-1){
			deu = 0;
			break;
		}
	}

	if(!deu) cout << ":(" << endl;
	else{
		fr(i, n) cout << v[i];
	}
}