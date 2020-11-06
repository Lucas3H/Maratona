#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
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
	int n;
	cin >> n;

	int inf = 0;
	ll resp = 0;

	ll x[110];
	fr(i, n) cin >> x[i];

	int z = 0, y = 0;

	x[n] = 0;

	frr(i, n-1){
		if((x[i-1] == 2 && x[i] == 3 )||(x[i-1] == 3 && x[i] == 2)){
			inf = 1;
		}	
		else if((x[i-1] == 2 && x[i] == 1 )||(x[i-1] == 1 && x[i] == 2)){
			resp += 3;
		}
		else{
			resp += 4;
		}

		if(x[i-1] == 3 && x[i] == 1 && x[i+1] == 2) resp--;
	}
	if(inf) cout << "Infinite" << endl;
	else cout << "Finite" << endl << resp << endl;
}
