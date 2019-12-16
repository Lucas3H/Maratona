#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 200010

int main(){
	ll n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;

	vector<pair<ll, int>> v;

	ll a[MAXN], b[MAXN];

	frr(i, n){
		cin >> a[i];
		v.pb(mp(a[i]+ta, 0));
	}

	frr(i, m){
		cin >> b[i];
		v.pb(mp(b[i], 1));
	}
	sort(b+1, b+m+1);

	sort(v.begin(), v.end());

	int s = v.size();

	ll A = 0, B = m;
	ll minimo = 2*MAXN;
	int ind = 0;

	fr(i, s){
		if(A + B < minimo){
			minimo = A+B;
		}

		if(v[i].second == 0) A++;
		else B--;
	}

	if(A + B < minimo) minimo = A+B;

	fr(i, v.size()) cout << v[i].first << " ";
	cout << endl;
	fr(i, v.size()) cout << v[i].second << "  ";
	cout << endl;

	cout << "m "<< minimo << endl;

	if(minimo <= k){
		cout << -1 << endl;
		return 0;
	}

	cout << b[m - (minimo - k) + 1] +tb << endl;
}