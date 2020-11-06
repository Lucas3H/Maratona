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
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 300010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n, m, mask;
int a[MAXN][10];

pii func(ll x){
	pii ret = mp(-1, -1);

	set<int> s;
	map<int, int> M;

	frr(i, n){
		int val = 0;
		fr(j, m){
			if(a[i][j] >= x) val = (val + (1 << j));
		}

		if(s.find(val) == s.end()){
			s.insert(val);
			M[val] = i;
		}
		
		//cout << val << " ";
	}
	//cout << endl;

	for(auto x: s){
		for(auto y: s){
			if((x|y) == (mask)){
				return mp(M[x], M[y]);
			}
		}
	}

	return mp(-1, -1);
}

void read(){
	cin >> n >> m;
	mask = ((1 << m) - 1);
	frr(i, n){
		fr(j, m) cin >> a[i][j];
	}
}

int main(){
	ios::sync_with_stdio(false);

	read();
	int l = 0, r = MOD, mid;

	while(l < r - 1){
		mid = (l+r)/2;
		pii p = func(mid);

		if(p == mp(-1, -1)){
			r = mid;
		}
		else{
			l = mid;
		}
	}

	pii p = func(l);

	cout << p.f << " " << p.s << endl;
}
