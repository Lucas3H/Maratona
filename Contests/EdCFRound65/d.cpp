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

	int quinze = 0;

	fr(i, 3){
		if(r[i]%5 == 0 && r[i+1]%5 == 0){
			a[i+1] = 15;
			quinze = 1;
		}
	}

	if(!quinze && r[0]%5 == 0){
		a[0] = 15;
		quinze = 1;
	}
	if(!quinze && r[3]%5 == 0){
		a[4] = 15;
		quinze = 1;
	}
	if(!quinze) a[5] = 15;


	int quinz = 0;
	fr(i, 3){
		if(r[i]%23 == 0 && r[i+1]%23 == 0){
			a[i+1] = 23;
			quinz = 1;
		}
	}

	if(!quinz && r[0]%23 == 0){
		a[0] = 23;
		quinz = 1;
	}

	if(!quinz && r[3]%23 == 0){
		a[4] = 23;
		quinz = 1;
	}
	if(!quinz) a[5] = 23;


	int quin = 0;
	fr(i, 3){
		if(r[i]%7 == 0 && r[i+1]%7 == 0){
			a[i+1] = 42;
			quin = 1;
		}
	}

	if(!quin && r[0]%7 == 0){
		a[0] = 42;
		quinz = 1;
	}

	if(!quin && r[3]%7 == 0){
		a[4] = 42;
		quin = 1;
	}
	if(!quin) a[5] = 42;

	fr(i, 4){
		if(!a[i] && a[i+1] > 0){
			a[i] = r[i]/a[i+1];
		}
	}

	fr(i, 4){
		if(!a[i] && a[i+1] > 0){
			a[i] = r[i]/a[i+1];
		}
	}

	fr(i, 4){
		if(!a[i] && a[i+1] > 0){
			a[i] = r[i]/a[i+1];
		}
	}

	fr(i, 4){
		if(!a[i] && a[i+1] > 0){
			a[i] = r[i]/a[i+1];
		}
	}

	for(int i = 4; i >= 1; i--){
		if(!a[i] && a[i-1] > 0){
			a[i] = r[i-1]/a[i-1];
		}
	}

	for(int i = 4; i >= 1; i--){
		if(!a[i] && a[i-1] > 0){
			a[i] = r[i-1]/a[i-1];
		}
	}

	for(int i = 4; i >= 1; i--){
		if(!a[i] && a[i-1] > 0){
			a[i] = r[i-1]/a[i-1];
		}
	}

	for(int i = 4; i >= 1; i--){
		if(!a[i] && a[i-1] > 0){
			a[i] = r[i-1]/a[i-1];
		}
	}


	if(a[5] == 0){
		a[5] = 4+8+16+15+42+23 - a[0] - a[1] - a[2] - a[3] - a[4];
	}

	cout << "! ";
	fr(i, 6) cout << a[i] << " ";

	cout << endl;
}