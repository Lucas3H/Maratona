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
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

vector<int> getBlocks(string s){
	vector<int> ret;

	int i = 0;

	while(i < s.size()){
		int j = i, ans = 0, davez = i;

		while(j < s.size() && s[j] == s[davez]){
			j++;
			ans++;
		} 

		i = j;
		ret.pb(ans);
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		int n;
		string s;
		cin >> n >> s;

		int sobra = 0;
		vector<int> b = getBlocks(s);

		for(int i = 0; i < b.size(); i++){
			sobra = min(i + 1, sobra + b[i] - 1);
		}

		if(sobra == b.size()){
			cout << b.size() << endl;
		}
		else{
			cout << sobra + (b.size() - sobra + 1)/2 << endl;
		}
	}
}
