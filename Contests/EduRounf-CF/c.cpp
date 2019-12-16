#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
//#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 1000000000

int main(){
	int n, z;
	cin >> n >> z;

	int v[200010];

	fr(i, n) cin >> v[i];

	sort(v, v + n);

	int i = 0, r = 0; 
	while(v[i] + z <= v[n-1] && i <= (n)/2 - 1){
		i++;
		r++;
	}

	int j = n-1, k = 0;
	while(v[0] + z <= v[j] && j >= n/2){
		j--;
		k++;
	}

//	cout << k << " " << r <<endl;

	cout << min(k, r) << endl;
}
