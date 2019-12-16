#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

int main(){
	string s;
	cin >> s;

	int soma = 0;

	fr(i, s.size()){
		soma += int(s[i]) - 48; // '0' é 48 na tabela ASCII
	}

	// Na tabela ASCII, '0' é 48 e como só estou interessado na paridade, não preciso fazer nada
	if(int(s[s.size()-1])%2 == 0) cout << "S" <<endl;
	else cout << "N" << endl;	

	if(soma%3 == 0) cout << "S" <<endl;
	else cout << "N" << endl;

	//Na tabela ASCII, '0' é 48 e '5' é 53, por isso somo 2
	if((int(s[s.size()-1])+2)%5 == 0) cout << "S" <<endl;
	else cout << "N" << endl;

	return 0;
}
