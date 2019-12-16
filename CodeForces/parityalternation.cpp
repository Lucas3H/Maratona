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

#define MAXN 100010

int main(){
	int n;
	cin >> n;

	pq<int> odd, even;

	fr(i, n){
		int x;
		cin >> x;

		if(x%2 == 0) even.push(x);
		else odd.push(x);
	}

	while(!even.empty() && !odd.empty()){
		even.pop();
		odd.pop();
	}

	if(even.empty()){
		ll sum = 0;

		if(odd.size() > 0) odd.pop();

		while(!odd.empty()){
			sum+=odd.top();
			odd.pop();
		}

		cout << sum << endl;
	}

	else{
		ll sum = 0;

		if(even.size() > 0) even.pop();

		while(!even.empty()){
			
			sum+=even.top();
			even.pop();
		}

		cout << sum << endl;
	}
}