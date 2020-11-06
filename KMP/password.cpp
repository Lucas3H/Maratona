// https://codeforces.com/problemset/problem/126/B
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

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;

	vector<int> lps = build(s);

	int ans = lps[s.size() - 1];

	int visto[10*MAXN];
	mem(visto, 0);

	fr(i, s.size()-1) visto[lps[i]] = 1;

	int j = lps[s.size()- 1];

	while(j > 0){
		if(visto[j]){
			fr(i, j) cout << s[i];
			cout << endl;
			return 0;
		}
		else j = lps[j-1];
	}

	cout << "Just a legend" << endl;
}
