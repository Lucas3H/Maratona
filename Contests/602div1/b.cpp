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

#define MAXN 200010
#define MOD 1000000007
#define LOGN 30
#define ROOT 1
#define INF 987654321

class BIT{
    public:
        int v[MAXN], bit[MAXN];
        int n;

        void update(int i, int val){
            while(i <= n){
                bit[i] += val;
                i += i & (-i);
            }
        }

        int query(int i){
            int sum = 0;

            while(i > 0){
                sum += bit[i];
                i -= i & (-i);
            }

            return sum;
        }

        int binary_search(int v){
	        int sum = 0, pos = 0;
	
            int i = LOGN;

        	while(i >= 0){
		        if(pos + (1 << i) < n && sum + bit[pos + (1 << i)] < v){
			        sum += bit[pos + (1 << i)];
			        pos += (1 << i);
		        }

                i--;
	        }

	        return pos + 1; 
        }

        void build(){
            fr(i, n+1) bit[i] = 0;
            frr(i, n) update(i, v[i]);
        }
};

BIT b;
pair<pii, int> query[MAXN];
pii aux[MAXN];
int a[MAXN];
int ans[MAXN];
int colocados = 0;
int n, m;

int solve(int k, int pos){
	for(int i = colocados + 1; i <= k; i++){
		b.update(-aux[i].s, 1);
	}

	colocados = k;

	return b.binary_search(pos);
}	

void read(){
	cin >> n;
	frr(i, n) {
		cin >> a[i];
		aux[i] = mp(a[i], -i);
	}
	
	sort(aux + 1, aux + n + 1);
	reverse(aux + 1, aux + n + 1);

	cin >> m;

	frr(i, m){
		cin >> query[i].f.f >> query[i].f.s;
		query[i].s = i;
	}
	sort(query + 1, query + m + 1);

	b.n = n;
	b.build();
}

int main(){
	ios::sync_with_stdio(false);
	read();
/*
	frr(i, n){
		cout << aux[i].f << " " << aux[i].s << endl;
	}
*/
	frr(i, m){
		ans[query[i].s] = solve(query[i].f.f, query[i].f.s);
	}
/*
	db;
	frr(i, n){
		cout << b.query(i) << endl;
	}

	db;
*/

	frr(i, m){
		cout << a[ans[i]] << endl;
	}
}
