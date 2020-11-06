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

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

matrix operator *(matrix a, matrix b){
    matrix ans(2, vector<ll>(2));

    fr(i, 2){
        fr(j, 2){
            ans[i][j] = 0;

            fr(k, 2) ans[i][j] = (a[i][k]*b[k][j] + ans[i][j])%MOD;
        }
    }

    return ans;
}

matrix fastxp(matrix a, ll e){
    if(e == 1) return a;

    matrix b = fastxp(a, e/2);

    b = b*b;
    if(e%2 == 1) b=b*a;

    return b;
}


int main(){
	
}