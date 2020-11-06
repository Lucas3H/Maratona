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

#define MAXN 1010
#define MOD 100000000000000.0

double total;
double d[MAXN], c[MAXN];
double me[MAXN];
int n;

/*

*/

double dp(int ini){
    if(ini == n+1) return 0;
    if(me[ini] > -1) return me[ini];

    double ans = MOD;
    for(int i = ini + 1; i <= n+1; i++) ans = min(ans, dp(i) + (d[i] - d[ini])*(d[i] - d[ini])/c[ini]);

    return me[ini] = ans;
}

int main(){

    mem(me, -1);

    scanf("%d", &n);
    double k;
    scanf("%lf", &k);
    d[n+1] = k;

    for(int i = 1; i <= n; i++) cin >> d[i] >> c[i];

	printf("%.3lf\n", dp(1));
}
