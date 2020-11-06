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
	int n;
	cin >> n;

	int fr[MAXN];
	mem(fr, 0);

	fr(i, n){
		int x;
		cin >> x;
		fr[x]++;
	}

	vector<int> inc, dec;

	int deu = 1;
	fr(i, MAXN){
		if(fr[i] > 2){
			cout << "NO" << endl;
			return 0;
		}
		if(fr[i] == 2){
			inc.pb(i);
			dec.pb(i);
		}
		if(fr[i] == 1){
			inc.pb(i);
		}
	}

	cout << "YES" << endl;

	cout << inc.size() << endl;

	fr(i, inc.size()) cout << inc[i] << " ";
	cout << endl;

	cout << dec.size() << endl;
	frm(i, dec.size()) cout << dec[i] << " ";
}

































