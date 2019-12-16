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
#define mod(a, n) a = a%n;
#define mx(a, b) a = max(a, b);

#define MAXN 100010
#define MOD 1000000007

int adj[55][55];
int ap[52];

matrix operator *(matrix a, matrix b){
    matrix ans(52, vector<ll>(52));

    fr(i, 52){
        fr(j, 52){
            fr(k, 52) {
                ans[i][j] += a[i][k]*b[k][j];
                ans[i][j] = ans[i][j]%MOD;
            }
        }
    }

    return ans;
}

matrix fastxp(matrix base, ll n){
    if(n == 1) return base;

    matrix ans = fastxp(base, n/2);
    ans = ans*ans;

    if(n%2 == 1) ans = ans*base;

    return ans;
}

int main(){
		ios::sync_with_stdio(false);

    int m, k;
    ll n;
    cin >> n >> m >> k;

    fr(i, k){
        char a, b;
        cin >> a >> b;

        if(a > 'Z') a = a - 'a' + 26;
        else a = a - 'A';

        if(b > 'Z') b = b - 'a' + 26;
        else b = b - 'A';

        ap[a] = 1;
        ap[b] = 1;

        adj[a][b] = 1;
    }

    int nuc = 0;
    fr(i, 52){
        if(ap[i]) nuc++;
    }

    int i = 0;
    while(nuc < m){

        if(!ap[i]){
            nuc++;
            ap[i] = 1;
        }

        i++;
    }

    matrix base(52, vector<ll>(52));

    fr(i, 52){
        if(!ap[i]) continue;

        fr(j, 52){
            if(adj[i][j] == 0) base[i][j] = 1;
        }
    }

    matrix ini(52, vector<ll>(52));
    fr(i, 52) if(ap[i]) ini[i][0] = 1;

    if(n == 1){
        cout << m << endl;
        return 0;
    }

    matrix ans = fastxp(base, n-1);
    ans = ans*ini;

    ll sum = 0;
    fr(i, 52){
        sum+=ans[i][0];
    }

    cout << (sum)%MOD << endl;
}
