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

#define MAXN 1000010
#define MOD 1000000007

ll pr[MAXN];
vector<ll> p;


void crivo(){

    for(ll i = 2; i <MAXN; i++){
        if(pr[i] == 0){
            p.pb(i);

            for(ll j = 2; j*i < MAXN; j++) pr[j*i] = 1;
        }
    }
}

int main(){
	ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    crivo();

    int i = 0;
    vector<ll> div;
    int mais = 0;

    while(n > 1 && i < p.size()){
        if(n%p[i] == 0){
            div.pb(p[i]);

            n/=p[i];
            while(n%p[i] == 0) {
                n/=p[i];
                mais++;
            }
        }

        i++;
    }

    if(n > 1) div.pb(n);

    if(div.size() > 1) cout << 1 << endl;
    else{
        cout << div[0] << endl;
    }
}
