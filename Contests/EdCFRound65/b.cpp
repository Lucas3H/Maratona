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

#define MAXN 100010

int main(){
	int a[6], r[4];
	mem(a, 0);

	cout << "? " << 1 << " " << 2<< endl;
	fflush(stdout);
	cin >> r[0];

	cout << "? " << 2 << " " << 3 << endl;
	fflush(stdout);
	cin >> r[1];

	cout << "? " << 3 << " " << 4 << endl;
	fflush(stdout);
	cin >> r[2];

	cout << "? " << 4 << " " << 5 << endl;
	fflush(stdout);
	cin >> r[3];

	int d = 0, b = 0, c = 0;
	fr(i, 3){
		if(r[i]%15 == 0 && r[i+1]%15 == 0){
			a[i+1] = 15;
			d = 1;
			//cout << "OLLAA" <<endl;
		}

		if(r[i]%42 == 0 && r[i+1]%42 == 0){
			a[i+1] = 42;
			b = 1;
		}

		if(r[i]%23 == 0 && r[i+1]%23 == 0){
			a[i+1] = 23;
			c = 1;
		}
	}

	if(r[0]%15 == 0 && r[1]%15 != 0){
			a[0] = 15;
			d = 1;
		}

	if(r[0]%42 == 0 && r[1]%42 != 0){
			a[0] = 42;
			b = 1;
		}

	if(r[0]%23 == 0 && r[1]%23 != 0){
		a[0] = 23;
			c = 1;
	}


	if(r[3]%15 == 0 && r[2]%15 != 0){
			a[4] = 15;
			d = 1;
		}

	if(r[3]%42 == 0 && r[2]%42 != 0){
			a[4] = 42;
			b = 1;
		}

	if(r[3]%23 == 0 && r[2]%23 != 0){
		a[4] = 23;
			c = 1;
	}

	if(d == 0) a[5] = 15;
	if(b == 0) a[5] = 42;
	if(c == 0) a[5] = 23;

	fr(I, 6){
		fr(i, 4){
			if(a[i] == 0 && a[i+1] > 0){
				a[i] = r[i]/a[i+1];
			}
		}
	}

	fr(I, 6){
		for(int i = 4; i >=1; i--){
			if(a[i] == 0 && a[i-1] > 0){
				a[i] = r[i-1]/a[i-1];
			}
		}
	}

	if(a[5] == 0)a[5] = 4+8+16+23+15+42 - a[0] - a[1] - a[2] - a[3] - a[4];

	cout << "! ";
	fr(i, 6) cout << a[i] << " ";

	cout << endl;
}