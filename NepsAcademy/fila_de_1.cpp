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

bool is_power_of_two(ll x){
	if(x == 1) return 0;
	else return ((x&(x-1)) == 0);

}

int main(){
	ll x;
	cin >> x;

	if(is_power_of_two(x+1)) cout << "S" << endl;
	else cout << "N" << endl;

	return 0;
}