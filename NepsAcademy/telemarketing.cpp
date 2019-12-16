#include<bits/stdc++.h>

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
#define pii pair<int,int>
#define mk make_pair
#define pq priority_queue

#define MAXN 100010


using namespace std;

int main(){
	int n, t;
	int cnt[1000010];

	cin >> n >> t;

	priority_queue<pii> a;

	frr(i, n){
		cnt[i] = 0;
		a.push(mk(0, -i));
	}

	for(int i = 0; i < t; i++){
		int dur;

		cin >> dur;

		pii davez = a.top();
		a.pop();

		cnt[-davez.second]++;

		a.push(mk(davez.first - dur, davez.second));
	}

	frr(i, n) cout << i << " " << cnt[i] << endl;

}