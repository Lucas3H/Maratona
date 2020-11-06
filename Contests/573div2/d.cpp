#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

map<ll, ll> fr;
ll n, extra, sum, val_extra;

void read(){
	cin >> n;
	fr(i, n){
		ll aux;
		cin >> aux;
		if(fr[aux] > 0){
			extra++;
			val_extra = aux;
		}

		fr[aux]++;
		sum+= aux;
	}
}

int main(){
	ios::sync_with_stdio(false);
	
	read();

	if(extra > 1 || fr[0] > 1 || fr[val_extra - 1] > 0){
		cout << "cslnb\n";
	}
	else{
		if((sum - n*(n-1)/2)%2 == 0) cout << "cslnb\n";
		else cout << "sjfnb\n";
	}
}
