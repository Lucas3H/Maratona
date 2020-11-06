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

#define ll long long

#define MAXN 100010

int main(){
	int n, m, r;
	cin >>n >> m >> r;

	int mi = 10000, sh = 0;
	fr(i, n){
		int s;
		cin >> s;
		if(s < mi){
			mi = s;
			sh = r/s;
		}
	}

	int M = 0, grana;
	for(int i = 0; i < m; i++){
		int s;
		cin >> s;
		if(s > M){
			grana = sh*s;
			M = s; 
		}
	}

	cout << max(r%mi + grana, r) << endl;

}
