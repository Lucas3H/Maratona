#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

int main(){
	int n;
	string s;

	cin >> n;
	cin >> s;

	int r = -1;
	fr(i, n-1){
		if(s[i] > s[i+1]){
			r = i;
			break;
		}
	}

	if(r == -1){
		cout << "NO" << endl;
	}	
	else{
		cout << "YES" <<endl << r + 1 <<" "<< r + 2 << endl;
	}
}