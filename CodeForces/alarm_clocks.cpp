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

int mdc(int a, int b){
	int x = max(a, b), y = min(a, b);

	while(x%y != 0){
		int aux = max(x-y, y);
		y = x - aux;
		x = aux;	
	}

	return y;

}

int main(){
	int n, m;

	cin >> n >> m;

	ll ant, atu;

	cin >> ant >> atu;
	ll md = atu - ant, first = ant;

	ant = atu;
	fr(i, n-2){
		cin >> atu;

		md = mdc(md, atu - ant);
		ant = atu;
	}

	int ind = -1;
	ll p;
	fr(i, m){
		cin >> p;
		if(md%p == 0){
			ind = i + 1;
			break;
		}
	}

	if(ind == -1) cout << "NO" << endl;
	else{
		cout << "YES" << endl << first << ' ' << ind << endl;
	}	
}
