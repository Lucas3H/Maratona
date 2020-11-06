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

vector<int> lps_p(string pat){
	int i = 1, len = 0, tam = pat.size(), c = 0;
	vector<int> lps(tam, 0);
	lps[0] = 0;

	while(i < tam){
		c++;

		if(pat[i] == pat[len]){
			lps[i++] = (len++) + 1;
			cout << 1 << endl;
		}
		else if(len != 0) {
			cout << 2 << endl;
			len = lps[len-1];
		}
		else {
			cout << 3 << endl;
			lps[i++] = 0;
		}
	}

	cout << c << " " << pat.size() << endl;

	return lps;
}

int main(){
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	vector<int> lps = lps_p(s);
}
