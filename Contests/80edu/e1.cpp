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

#define MAXN 600010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321
#define LOGN 20

int n, m;

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

int pos[MAXN], ans[MAXN], used[MAXN], a[MAXN];
BIT b;

void read(){
	cin >> n >> m;
	
	frr(i, m){
		cin >> a[i];
		used[a[i]] = 1;
	}

	b.n = n + m + 1;

	frr(i, n){
		b.v[i] = 1;
		pos[i] = n - i + 1;
		ans[i] = i;
	}

	b.build();

}

void change(int ind, int new_pos){
	int val = n - b.query(pos[ind] - 1);

	//cout << ind << " ||| " << val << endl;

	ans[ind] = max(ans[ind], val);
	if(new_pos < n + m + 1) b.update(pos[ind], -1);

	pos[ind] = new_pos;
	b.update(pos[ind], 1);
}

int main(){
	read();

	frr(i, m){
		change(a[i], n + i);
	}

	frr(i, n){
		change(i, n + m + 1);
	}

	frr(i, n){
		if(used[i]) cout << 1 << " ";
		else cout << i << " ";
	
		cout << ans[i] << endl;
	}
}
