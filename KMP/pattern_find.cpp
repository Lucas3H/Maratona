// https://www.spoj.com/problems/NAJPF/
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

vector<int> build(string s){
	int t = s.size(), i = 1, j = 0;
	vector<int> lps(t);

	lps[0] = 0;

	while(i < t){
		if(s[i] == s[j]) lps[i++] = (j++) + 1;
		else if(j == 0) lps[i++] = 0;
		else j = lps[j-1];
	}

	return lps;
}

vector<int> pos;
int check(string s, string p){
	vector<int> lps = build(p);
	pos.clear();
	int ts = s.size(), tp = p.size(), i = 0, j = 0, ans = 0;

	while(i < ts){
		if(s[i] == p[j]){
			i++;
			j++;
		}

		if(j == tp){
			ans++;
			pos.pb(i - tp);
			j = lps[j-1];
		}

		else if(i < ts && s[i] != p[j]){
			if(j == 0) i++;
			else j = lps[j-1];
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		string s, p;
		cin >> s >> p;

		int k = check(s, p);

		if(k == 0) cout << "Not Found\n";
		else{
			cout <<k << endl;
			fr(i, pos.size()) cout << pos[i] + 1 <<  " ";
			cout << endl;
		}

		cout << endl;
	}
}
