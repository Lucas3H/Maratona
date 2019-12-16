// 
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
		else if( j == 0) lps[i++] = 0;
		else j = lps[j-1];
	}

	return lps;
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;
		vector<int> lps = build(s);

		int tam = s.size() - lps[s.size() - 1];

		if(tam == s.size() || s.size()%tam != 0){
			cout << s.size() << endl;
			if(t)cout << endl;
			continue;
		}

		int deu = 1;
		for(int i = 0; i < s.size()/tam; i++){
			for(int j = 0; j < tam; j++){
				if(s[i*tam + j] != s[j]) deu = 0;
			}
		}

		if(deu) cout << tam << endl;
		else cout << s.size() << endl;

		if(t > 0) cout << endl;
	}
}
