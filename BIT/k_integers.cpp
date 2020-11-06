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
int pos[MAXN], v[MAXN];
int ant = 0;

void solve(int ind){
	int ml = b.binary_search(1);
	int mr = b.binary_search(ind - 1);
	
	cout << ind << " "<< ml << " " << mr << " " << pos[ind] << endl;

	if(ml > pos[ind])
		ant += (ml - pos[ind] - 1) + ind - 1;
	else if(mr < pos[ind])
		ant += (pos[ind] - mr - 1);
	else{
		int q = b.query(pos[ind]);
		int l = b.binary_search(q);
		int r = b.binary_search(q + 1);

		ant += min(ind-1 + pos[ind] - l - 1, r - pos[ind] - 1);
	}

	//cout << ant << " ";

	b.update(pos[ind], 1);
}

int main(){
	ios::sync_with_stdio(false);

	cin >> b.n;

	frr(i, b.n) {
		cin >> v[i];
		pos[v[i]] = i;
	}

	cout << ant << " ";
	b.update(pos[1], 1);

	for(int i = 2; i <= b.n; i++){
		solve(i);
	}

	cout << endl;
}