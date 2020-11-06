#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

int acu[3001][3001];
pii pt[3001];
int n;

map<int, int> x, y, auxX, auxY;

void build(){
	frr(i, n){
		frr(j, n){
			acu[i][j] = (acu[i][j] + acu[i-1][j] + acu[i][j-1] - acu[i-1][j-1]);
		}
	}
}

void read(){
	cin >> n;

	frr(i, n){
		cin >> pt[i].f >> pt[i].s;
		auxX[pt[i].f]++;
		auxY[pt[i].s]++;
	}

	int ix = 1;
	for(auto aux: auxX){
		x[aux.f] = ix++;
	}

	int iy = 1;
	for(auto aux: auxY){
		y[aux.f] = iy++;
	}
  
	frr(i, n){
		acu[x[pt[i].f]][y[pt[i].s]] = 1;
		pt[i] = {x[pt[i].f], y[pt[i].s]};
	}

	build();
}

int get(int x1, int y1, int x2, int y2){
	if(x1 > x2) swap(x1, x2);
	if(y1 > y2) swap(y1, y2);

	return acu[x2][y2] - acu[x2][y1 - 1] - acu[x1 - 1][y2] + acu[x1 - 1][y1 - 1];
}

int main(){
	ios::sync_with_stdio(false);

	read();

	/*
	frr(i, n){
		frr(j, n){
			cout << acu[i][j] << " ";
		}
		cout << endl;
	}
	*/

	int ans = 0;

	frr(i, n){
		frr(j, i-1){
			if(get(pt[i].f, pt[i].s, pt[j].f, pt[j].s) == 2)
				ans++;
		}
	}

	cout << ans << endl;
}
