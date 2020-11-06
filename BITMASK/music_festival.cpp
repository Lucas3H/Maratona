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

int n, greatest_begin = 0;
ll memo[(1 << 10) + 2][86410];
vector<pair<int, pii>> stage[11];

int dp(int mask, int end){

    //cout << mask << " fsdfsfs  " << end << endl;


    if(end >= greatest_begin && mask != ((1 << n) - 1)) return -MOD;
    else if(end >= greatest_begin) return 0;

    if(memo[mask][end] != -1) return memo[mask][end];

    ll ans = -MOD;

    fr(i, n){
        int tam = stage[i].size();

        if(stage[i][tam-1].f < end) continue;

        int ini = 0, fim = tam, meio;

        while(ini < fim){
            meio = (ini + fim)/2;

            if(stage[i][meio].f <= end && stage[i][meio + 1].f > end) break;
            if(stage[i][meio].f < end) ini = meio + 1;
            else fim = meio;

            //cout<< mask << " " << end << endl;
            //cout << i << " " << ini << " " << fim << endl;
        }

        if(stage[i][meio].f < end) meio++;
/*
        cout << stage[i][meio].f << endl;
        cout << mask << " " << end << endl;
*/
        while(meio < tam){
            ans = max(ans, dp( (mask | (1 << i)) , stage[i][meio].s.f) + (ll)stage[i][meio].s.s);
            meio++;
        }
    }

    //cout << mask << " " << end << " " << ans << endl;

    return memo[mask][end] = ans;
}

int main(){
    ios::sync_with_stdio(false);

    mem(memo, -1);

    cin >> n;
    fr(i, n){
        int show, b, e, o;
        cin >> show;

        fr(j, show){
            cin >> b >> e >> o;
            stage[i].pb(mp(b, mp(e, o)));

            if(b > greatest_begin) greatest_begin = b;
        }

        sort(stage[i].begin(), stage[i].end());
    }

    ll d = dp(0, 0);
    if(d < 0) cout << -1 << endl;
    else cout << d << endl;
}
