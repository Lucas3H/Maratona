#include<bits/stdc++.h>
using namespace std;


#define frr(i, n) for(int i = 1; i <= n; i++)
#define MAXN 500019 // Number of words * Maximum length


int trie[MAXN][26];
int isEnd[MAXN]; // True if i-th node of trie is end of word

string m[MAXN];

class TRIE{
public:
	// Original code: https://github.com/mrfelipenoronha/competitive-programming/blob/master/algos_notebook/data_structures/tries.cpp
	
	// Store and check for strings

	TRIE(){	
		memset(trie, -1, sizeof(trie));
		memset(isEnd, 0, sizeof(isEnd));
	}

	int cnt = 1; // Latest node - trie[0] == root

	void add(string str, int idx, int node, int ind){
		// If its already in the end
		if (str.length() == idx){
			isEnd[node] = ind;
			return;
		}

		int &lidx = trie[node][ str[idx]-'a' ]; // Change for 0 if it's number
		
		// If there is no following to that letter
		if (lidx == -1)
			lidx = cnt++;

		add(str, idx+1, lidx, ind);
	}

	int search(string str, int idx, int node){
		// Found
		if (idx == str.length()){
			return node;
		}

		int &lidx = trie[node][ str[idx]-'a' ]; // Change for 0 if it's number
		// Not found
		if (lidx == -1)
			return -1;

		return search(str, idx+1, lidx);
	};

	void print(int node){
		if(isEnd[node]){
			cout << m[isEnd[node]] << endl;
		}

		for(int i = 0; i < 26; i++){
			if(trie[node][i] > -1) print(trie[node][i]);
		}
	}
};

int main(){
	TRIE t;

	int n, k;
	cin >> n;
	frr(i, n){
		string s;
		cin >> s;

		m[i] = s;
		t.add(s, 0, 0, i);
	}

	cin >> k;

	frr(i, k){
		string s;
		cin >> s;
		cout << "Case #"<< i << ":\n";
		int nd = t.search(s, 0, 0);
		if(nd == -1){
			cout << "No match.\n";
		}
		else{
			for(int i = 0; i < 26; i++){
				if(trie[nd][i] > -1) t.print(trie[nd][i]);
			}
		}
	}
}