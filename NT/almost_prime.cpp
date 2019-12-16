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

#define MAXN 1000010
#define MOD 1000000007
#define eps 0.0000001

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

int main(){
	ios::sync_with_stdio(false);

    crivo();
    int t;
    cin >> t;

    while(t--){
        ll a, b;
        cin >> a >> b;

        ll ans = 0;
        fr(i, p.size()){
            //cout << p[i] <<" ";
            ans += (ll)floor((log(b) + eps)/log(p[i]));
            //cout << floor((log(b) + eps)/log(p[i])) << " ";

            if(a > 1){
                ans -= (ll)floor((log(a) - eps)/log(p[i]));
                //cout << floor((log(a) - eps)/log(p[i])) << " ";
            }

            if(p[i] >= a && p[i] <= b) ans--;

            //cout << ans << endl;
        }

        cout << ans << endl;
    }
}
