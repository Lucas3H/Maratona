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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int n;
pii p[MAXN];
vector<pii> line;
int n_yc = 0;
map<int, int> yc;

int nd[4*MAXN];

void update(int i, int l, int r, int pos, int val){
	if(l == r){
		nd[i] = max(nd[i], val);
	}
	else{
		int m = (l+r)/2;
		if(pos <= m)
			update(2*i, l, m, pos, val);
		else
			update(2*i+1, m+1, r, pos, val);

		nd[i] = max(nd[2*i], nd[2*i+1]);
	}
}

int query(int i, int l, int r, int ql, int qr){
	if(ql > r || l > qr) return 0;
	else if(ql <= l && r <= qr) return nd[i];
	else{
		int m = (l+r)/2;

		return max(query(2*i, l, m, ql, qr), query(2*i + 1, m+1, r, ql, qr));
	}
}

void read(){
	cin >> n;

	cin >> p[0].f >> p[0].s >> p[n+1].f >> p[n+1].s;
	frr(i, n) cin >> p[i].f >> p[i].s;

	frm(i, n+2){
		p[i].f -= p[0].f;
		p[i].s -= p[0].s;
	}

	if(p[n+1].f >= 0 && p[n+1].s < 0){
		fr(i, n+2){
			p[i].s = -p[i].s;
		}
	}
	else if(p[n+1].f < 0 && p[n+1].s < 0){
		fr(i, n+2){
			p[i].s = -p[i].s;
			p[i].f = -p[i].f;
		}
	}
	else if(p[n+1].f < 0 && p[n+1].s >= 0){
		fr(i, n+2){
			p[i].f = -p[i].f;
		}
	}

	set<int> aux;

	fr(i, n+1){
		if(p[i].f >= p[0].f && p[i].f <= p[n+1].f && p[i].s >= p[0].s && p[i].s <= p[n+1].s){
			line.pb(p[i]);
			aux.insert(p[i].s);
		}
	}

	for(auto x: aux){
		n_yc++;
		yc[x] = n_yc;
	}

	sort(line.begin(), line.end());
}

void solve(){
	/*
	cout << "----\n";
	fr(i, n+2){
		cout << p[i].f << " " << p[i].s << endl; 
	}
	cout << "--------\n";
	*/

	//cout << n_yc << endl;
	for(int i = line.size() - 1; i >= 1; i--){
		//cout << line[i].f << ' ' << line[i].s << endl;
		int maximo = query(1, 1, n_yc, yc[line[i].s], n_yc);
		
		update(1, 1, n_yc, yc[line[i].s], maximo + 1);	
	}

	cout << query(1, 1, n_yc, 1, n_yc) << endl;
}

int main(){
	ios::sync_with_stdio(false);
	read();
	solve();
}
