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

int n;
int bit[1030][1030];
int m[1030][1030];

void update(int i, int j, int val){
    for(int k = j; k <= n; k += k & (-k)){
        for(int l = i; l <= n; l += l & (-l)){
            bit[k][l] += val;
        }
    }
}

int query(int i, int j){
    int sum = 0;

    for(int k = j; k > 0; k -= k & (-k)){
        for(int l = i; l > 0; l -= l & (-l)){
            sum += bit[k][l];
        }
    }

    return sum;
}

int sum_ret(int x1, int y1, int x2, int y2){
    return query(x2, y2) + query(x1 - 1, y1 - 1) - query(x2, y1 - 1) - query(x1 - 1, y2);
}

int main(){
	ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        cin >> n;
        frr(i, n) {
            frr(j, n){
                bit[i][j] = 0;
                m[i][j] = 0;
            }
        }

        string op;
        int x, y, z, w;
        cin >> op;

        while(op[0] != 'E'){

            if(op[1] == 'E'){
                cin >> x >> y >> z;

                update(x + 1, y + 1, z - m[y+1][x+1]);
                m[y+1][x+1] = z;
            }
            else{
                cin >> x >> y >> z >> w;
                cout << sum_ret(x + 1, y + 1, z + 1, w + 1) << endl;
            }

            cin >> op;
        }

        cout << endl;
    }
}
