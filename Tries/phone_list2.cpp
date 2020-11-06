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

#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

#define MAXN 100019 

int trie[MAXN][26];
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

	bool add(string str, int idx, int node){
		// If its already in the end
		if (str.length() == idx){
			isEnd[node] = true;
			return 0;
		}

		int &lidx = trie[node][ str[idx]-'0' ]; // Change for 0 if it's number
		
		// If there is no following to that letter
		if (lidx == -1)
			lidx = cnt++;

		int aux = add(str, idx+1, lidx);

		if(isEnd[node]) 
			return 1;
		else return aux;
	}

	bool search(string str, int idx, int node){
		// Found
		if (idx == str.length())
			return true;

		int &lidx = trie[node][ str[idx]-'0' ]; // Change for 0 if it's number
		// Not found
		if (lidx == -1)
			return false;

		return search(str, idx+1, lidx);
	};
};

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		TRIE T;

		int n;
		cin >> n;

		int deu = 0;

		while(n--){
			string s;
			cin >> s;
			if(T.search(s, 0, 0) || T.add(s, 0, 0)) deu = 1; 
		}

		if(deu) cout << "NO\n";
		else cout << "YES\n";
	}
}
