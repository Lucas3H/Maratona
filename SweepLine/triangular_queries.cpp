// 
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

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

struct Query{
	int tipo, x, y, d, idx;
};

bool comp(Query a, Query b){
	if(a.x == b.x) return a.tipo < b.tipo;
	else return a.x < b.x;
}

int tira[MAXN], bit[2][MAXN], poe[MAXN], ans[MAXN];
int n, queries;
vector<Query> q; 

void update(int i, int val, int ind){
    while(i <= MAXN){
        bit[ind][i] += val;
        i += i & (-i);
    }
}

int query(int i, int ind){
    int sum = 0;

    while(i > 0){
        sum += bit[ind][i];
        i -= i & (-i);
    }

    return sum;
}

void build(int ind){
    fr(i, MAXN) bit[ind][i] = 0;
}

void read(){

	cin >> n >> queries;

	frr(i, n){
		Query a;
		cin >> a.x >> a.y;
		a.d = 0;
		a.tipo = 1;

		q.pb(a);
	}

	frr(i, queries){
		Query a;
		cin >> a.x >> a.y >> a.d;
		a.tipo = 0;
		a.idx = i;

		q.pb(a);

		a.x = a.x + a.d;
		a.tipo = 2;

		q.pb(a);
	}

	sort(q.begin(), q.end(), comp);

	build(0);
	build(1);
	
}

int main(){
	read();

	fr(i, q.size()){
		if(q[i].tipo == 1){
			update(q[i].x + q[i].y, 1, 0);
			update(q[i].y, 1, 1);
		}
		else if(q[i].tipo == 0){
			tira[q[i].idx] = query(q[i].x + q[i].y + q[i].d, 0);
			poe[q[i].idx] = query(q[i].y - 1, 1);
		}
		else{
			//cout << query(q[i].x + q[i].y, 0) << " " << tira[q[i].idx] << " " <<  query(q[i].y - 1, 1) << ' ' << poe[q[i].idx] << endl;
			ans[q[i].idx] = query(q[i].x + q[i].y, 0) - tira[q[i].idx] - query(q[i].y - 1, 1) + poe[q[i].idx];
		}
	}

	frr(i, queries) cout << ans[i] << endl;
	cout << endl;
}
