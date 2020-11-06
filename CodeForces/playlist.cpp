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

#define MAXN 300010

int main(){
	int n, k;
	cin >> n >> k;

	vector<pair<ll, ll>> s;
	fr(i, n) {
		ll l, b;
		cin >> l >> b;

		s.pb(mp(b, l)); 
	}

	sort(s.begin(), s.end());

	ll sum = 0;

	vector<ll> p;
	pq<ll, vector<ll>, greater<ll>> largest;

	frm(i, n){
		if(n-i < k){
			sum += s[i].second;
			largest.push(s[i].second);
			p.pb(sum*s[i].first);
		}
		else{
			p.pb((sum+s[i].second)*s[i].first);
			
			if(!largest.empty() && largest.top() < s[i].second){
				sum += s[i].second - largest.top();
				largest.pop();
				largest.push(s[i].second);
 			}
		}
	}

	ll resp = 0;
	fr(i, n){
		if(p[i] > resp) resp = p[i];
	} 

	cout << resp <<endl;

}