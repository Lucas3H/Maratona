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
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define LOGN 20

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

        /*Lower_bound*/
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

int main(){
	ios::sync_with_stdio(false);
    cin >> n;
    frr(i, n) cin >> v[i];

    build();

    frr(i, n) cout << query(i) << " ";
    cout << endl;

    int q;
    while(q--){
        int op, a, b;
        cin >> op >> a;

        if(op == 0) {
            cin >> b;
            update(a, b);
        }
        else cout << query(a) << endl;
    }
}
