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

#define MAXN 100010

int main(){
	int n;

	cin >> n;

	vector<pii> v;

	int ini, fim;
		
	fr(i, n){
		cin >> ini >> fim;

		v.pb(mp(fim, ini));
	}

	sort(v.begin(), v.end());

	int resp = 0;
	int final = -1;
	fr(i, n){
		if(v[i].second >= final){
			resp++;
			final = v[i].first;

		}
	}

	cout << resp << endl;

}
