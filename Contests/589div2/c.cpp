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

int composto[MAXN];
vector<ll> p;

void crivo(){
    for(int i = 2; i < MAXN; i++){
        if(composto[i] == 0){
            p.pb( (ll)i );
            for(int j = 2; j < MAXN/i; j++) composto[i*j] = 1;
        }
    }
}

ll fastxprec(ll base, ll e){
    if(e == 0) return 1;
    ll ans = fastxprec(base, e/2);

    ans *= ans;
    ans = ans%MOD;
    if(e%2 == 1) ans*= base;
    ans = ans%MOD;

    return ans;
}


int main(){
	ios::sync_with_stdio(false);

    ll x, n;
    cin >> x >> n;

    crivo();

    vector<ll> px;

    fr(i, p.size()){
        if(x%p[i] == 0){
            px.pb(p[i]);
            while(x%p[i] == 0) x/=p[i];
        }
    }

    if(x > 1) px.pb(x);

    //fr(i, px.size()) cout << px[i] << " ";

    ll ans = 1;

    ll apareceu = 0;
    ll P = 1;
    fr(i, px.size()){
        //cout << px[i] << endl;

        P = 1;
        apareceu = 0;

        int d = floor((log(n) + 0.000001)/log(px[i]));

        fr(j, d){

            P *= px[i];
            apareceu += n/P;

        }
//        cout << apareceu << endl;

        ans *= fastxprec(px[i], apareceu);
        ans = ans%MOD;
    }

    cout << ans << endl;

}
