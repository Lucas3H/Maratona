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

#define MAXN 200010
#define MOD 1000000007

vector<int> a[3];

int main(){
	ios::sync_with_stdio(false);

    int k[3], p[3];
    int lig[MAXN];
    
    fr(i, 3) cin >> k[i];

    int n = k[1] + k[2] + k[0];

    int aux;

    fr(i, 3){
        a[i].pb(0);
        frr(j, k[i]) {
            cin >> aux;
            lig[aux] = i;

            a[i].pb(aux);
        }

        sort(a[i].begin(), a[i].end());
    }

    fr(i, 3) p[i] = k[i];

    int best_l[MAXN], total_l[MAXN];
    int saldo = 0;

    best_l[0] = 0;

    frr(i, n+1){
        best_l[i] = saldo;
        if(lig[i] == 0) saldo--;
        else if(lig[i] == 1) saldo++;

        best_l[i] = min(best_l[i], best_l[i-1]);
    }

    int ans = MAXN;
    int rm = 0;

    for(int i = n + 1; i > 0; i--){
        fr(j, 3){
            if(a[j][p[j]] == i) p[j]--;
        }

        ans = min(ans, best_l[i] + k[0] + p[2] + k[1] - p[1]);
    }

    cout << ans << endl;
}
