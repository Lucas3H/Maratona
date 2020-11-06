#include<bits/stdc++.h>
using namespace std;

#define MAXN 10019 // Number of words * Maximum length

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

	void add(string str, int idx, int node){
		// If its already in the end
		if (str.size() == idx){
			isEnd[node] = true;
			return;
		}

		int &lidx = trie[node][ str[idx]-'a' ]; // Change for 0 if it's number
		
		// If there is no following to that letter
		if (lidx == -1)
			lidx = cnt++;

		add(str, idx+1, lidx);
	}

	bool search(string str, int idx, int node){
		// Found
		if (idx == str.size())
			return true;

		int &lidx = trie[node][ str[idx]-'a' ]; // Change for 0 if it's number
		// Not found
		if (lidx == -1)
			return false;

		return search(str, idx+1, lidx);
	};
};

int main(){
	TRIE t;

	add("Ola", 0, 0);
	cout << search("oi", 0, 0) << endl;
}