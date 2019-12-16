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

#define MAXN 300010

bool ord(int a, int b){
	return a > b;
}

int main(){
	int n, m;
	cin >> n >> m;

	int a[MAXN], b[MAXN];
	fr(i, m){
		cin >> a[i] >> b[i];
	}

	int x = 0, y = 0;

	fr(i, m){
		if(a[0] != a[i] && a[0] != b[i] && b[0] != a[i] && b[0] != b[i]){
			x = a[i];
			y = b[i];
			break;
		} 
	}




	if(x == 0 && y == 0){
		cout << "YES" << endl;
		return 0;
	}

	int deu = 1;

	fr(i, m){
		if(a[0] != a[i] && a[0] != b[i] && x != a[i] && x != b[i]){
			deu = 0;
			break;
		} 
	}

	if(deu == 1){
		cout << "YES" << endl;
		return 0;
	}











	deu = 1;

	fr(i, m){
		if(a[0] != a[i] && a[0] != b[i] && y != a[i] && y != b[i]){
			deu = 0;
			break;
		
		} 
	}

	if(deu == 1){
		cout << "YES" << endl;
		return 0;
	}











	deu = 1;

	fr(i, m){
		if(x != a[i] && x != b[i] && b[0] != a[i] && b[0] != b[i]){
			deu = 0;
			break;
		} 
	}

	if(deu == 1){
		cout << "YES" << endl;
		return 0;
	}











	deu = 1;

	fr(i, m){
		if(y != a[i] && y != b[i] && b[0] != a[i] && b[0] != b[i]){
			deu = 0;
			break;
		} 
	}

	if(deu == 1){
		cout << "YES" << endl;
		return 0;
	}

	cout << "NO" << endl;
}