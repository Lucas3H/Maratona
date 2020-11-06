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

#define MAXN 6000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int trie[MAXN][2];
int fr[MAXN][2];
bool isEnd[MAXN]; // True if i-th node of trie is end of word

class TRIE{
public:
	// Original code: https://github.com/mrfelipenoronha/competitive-programming/blob/master/algos_notebook/data_structures/tries.cpp
	
	// Store and check for strings

	TRIE(){	
		memset(trie, -1, sizeof(trie));
		memset(isEnd, 0, sizeof(isEnd));
	}

	int cnt = 1; // Latest node - trie[0] == root

	void add(vector<int> v, int idx, int node){
		if (v.size() == idx){
			isEnd[node] = true;
			return;
		}

		int &lidx = trie[node][v[idx]];
		fr[node][v[idx]]++;
		if (lidx == -1)
			lidx = cnt++;

		add(v, idx+1, lidx);
	}

	void remove(vector<int> v, int idx, int node){
		// If its already in the end
		if (v.size() == idx){
			return;
		}

		int &lidx = trie[node][v[idx]]; 

		fr[node][v[idx]]--;
		if (lidx == -1)
			lidx = cnt++;

		remove(v, idx+1, lidx);
	}

	vector<int> search(vector<int> v, int idx, int node){
		if (idx == v.size()){
			vector<int> a;
			return a;
		}
		
		if(fr[node][1 - v[idx]]){
			vector<int> ret = search(v, idx + 1, trie[node][1 - v[idx]]);
			ret.pb(1 - v[idx]);
		
			return ret;
		}
		else{
			vector<int> ret = search(v, idx + 1, trie[node][v[idx]]);
			ret.pb(v[idx]);
		
			return ret;
		}
	};
};

vector<int> make_bin(int x){
	vector<int> ret;
	for(int i = 0; i < 30; i++){
		ret.pb(x%2);
		x/=2;
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	int q;
	cin >> q;

	TRIE T;

	T.add(make_bin(0), 0, 0);

	while(q--){
		char c;
		int x;
		cin >> c >> x;

		if(c == '+')
			T.add(make_bin(x), 0, 0);
		else if(c == '-')
			T.remove(make_bin(x), 0, 0);
		else{
			vector<int> a = make_bin(x), b = T.search(a, 0, 0);
			reverse(a.begin(), a.end());

			int ans = 0;
			fr(i, 30){
				ans += ((1 << i)*((a[i]^b[i])));
			}

			cout << ans << endl;

		}
	}
}
