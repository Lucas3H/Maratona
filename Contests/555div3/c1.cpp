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

	int x[MAXN];
	fr(i, n) cin >> x[i];

	vector<char> v;
	vector<int> resp, a , b;
	set<int> s;

	a.pb(x[0]);
	fr(i, n-1){
		if(x[i] >= x[i+1]) break;

		a.pb(x[i+1]);
	}

	b.pb(x[n-1]);
	for(int i = n-1; i>0; i--){
		if(x[i] >= x[i-1]) break;

		b.pb(x[i-1]);
	}

	int left = 0, right = 0; 


	while(true){
		if(left == a.size() && right == b.size()) 
			break;
		if(left == a.size()){
			v.pb('R');
			right++;

			continue;
		}
		if(right == b.size()){
			v.pb('L');
			left++;
			continue;
		}

		if(a[left] > b[right]){
			v.pb('R');
			right++;
		}
		else if(a[left] < b[right]){
			v.pb('L');
			left++;
		}
		else{
			int l = a.size() - left, r = b.size() - right;

			if(l > r) fr(k, l) v.pb('L');
			else fr(k, r) v.pb('R');

			break;
		}
	}

	cout << v.size() << endl;;

	fr(i, v.size()) cout << v[i];

}