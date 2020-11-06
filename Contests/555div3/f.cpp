#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 200010

int main(){
	ll n;
	cin >> n;
	ll h[MAXN];
	mem(h, 0);

	fr(i, n){
		int x;
		cin >> x;

		h[x]++;
	}

	ll ini = 0, fim = 0;

	vector< pair<ll, pii> > interval;

	ll tam;

	frr(i, MAXN-1){
		if(h[i] > 0 && h[i-1] == 0){
			tam = h[i];
			ini = i;
			fim = i;
		}

		else if(h[i] > 0 && h[i-1] > 0){
			tam += h[i];
			fim = i;
		}

		if(h[i] == 1){
			interval.pb(mp(tam, mp(ini, fim)));
			tam = h[i];
			ini = i;
			fim = i;
		}
		else if(h[i] == 0){
			interval.pb(mp(tam, mp(ini, fim)));
		}
	}

	ll resp = 0, ind;
	fr(i, interval.size()){
		if(interval[i].first > resp){
			resp = interval[i].first;
			ind = i;
		}
	}

	ini = interval[ind].second.first, fim = interval[ind].second.second;

	cout << resp << endl;
	for(int i = ini; i <= fim; i++) cout << i << " ";

	for(int i = fim; i >= ini; i--){
		for(int j = 0; j < h[i] - 1; j++) cout << i << " "; 
	}
}