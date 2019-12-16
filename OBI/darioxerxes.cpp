#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int m[6][6];

int main(){
		ios::sync_with_stdio(false);
    m[0][1] = 1;
    m[0][2] = 1;
    m[1][2] = 1;
    m[1][3] = 1;
    m[2][3] = 1;
    m[2][4] = 1;
    m[3][4] = 1;
    m[3][0] = 1;
    m[4][0] = 1;
    m[4][1] = 1;

    int n;
    cin >> n;

    int a, b;
    int d= 0, x = 0;

    fr(i, n){
        cin >> a >>b;
        d+=m[a][b];
        x+=(1-m[a][b]);
    }

    if(d > x) cout << "dario" << endl;
    else cout << "xerxes" << endl;
}
