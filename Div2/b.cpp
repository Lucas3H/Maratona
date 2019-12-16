#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

int main(){
	int n;
	cin >> n;

	char m[55][55];

	fr(i, n){
		frj(j, n) cin >> m[i][j];
	}

	int deu = 1;
	for(int i = 0; i < n-2; i++){
		if(m[i][0] == '.') deu = 0;
		if(m[i][n-1] == '.') deu = 0;

		for(int j = 1; j < n-1; j++){
			if(m[i][j] == '.'){
				if(m[i+1][j-1] == '#' || m[i+1][j] == '#' || m[i+1][j+1] == '#' || m[i+2][j] == '#') deu = 0;
				else{
					m[i+1][j-1] = '#';
					m[i+1][j] = '#';
					m[i+1][j+1] = '#';
					m[i+2][j] = '#';
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(m[n-1][i] == '.') deu = 0;
	}


	for(int i = 0; i < n; i++){
		if(m[n-2][i] == '.') deu = 0;
	}

	if(deu) cout << "YES" << endl;
	else cout << "NO" << endl;
}
