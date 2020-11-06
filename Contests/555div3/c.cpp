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
		
	a.pb(x[0]);
	fr(i, n-1){
		if(x[i] > x[i+1]) break;

		a.pb(x[i+1]);
	}

	b.pb(x[n-1]);
	for(int i = n-1; i>0; i--){
		if(x[i] > x[i-1]) break;

		b.pb(x[i-1]);
	}

	int M = a.size() + b.size();

	int m = min(M, n);

	cout << min(M, n) << endl;

	int left = 0, right = 0; 

	fr(i, m){
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
		else{
			v.pb('L');
			left++;
		}
	}

	fr(i, m) cout << v[i];

}