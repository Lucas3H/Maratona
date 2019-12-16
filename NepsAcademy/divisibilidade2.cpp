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
		soma += int(s[i]) - 48;
	}

	int dois_ultimos_digitos;
	if(s.size() == 1) dois_ultimos_digitos = int(s[0]) - 48;
	else dois_ultimos_digitos = 10*(int(s[s.size()-2]) - 48) + int(s[s.size()-1]) - 48; 

	if(dois_ultimos_digitos%4 == 0) cout << "S" <<endl;
	else cout << "N" << endl;	

	if(soma%9 == 0) cout << "S" <<endl;
	else cout << "N" << endl;


	if(dois_ultimos_digitos%25 == 0) cout << "S" <<endl;
	else cout << "N" << endl;

	return 0;
}
