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

ll n, m;

ll f(ll x){
	if(x > 2*m || x < 2) return 0;
	else if(m + 1 >= x) return x - 1;
	else return 2*m + 1 - x;
}

int main(){
	cin >> n >> m;

	if(3*m < n) cout << 0 << endl;
	else{
		ll resp = 0;

		frr(i, m) resp += f(n - i);

		cout << resp << endl;
	}

	return 0;

}