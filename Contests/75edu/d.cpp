#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll, ll> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

vector<pii> r;
vector<pii> aux;
ll n, s;

ll deu(ll x){
    if(x > aux[n/2].f) return 0;

    ll gasto = x;

    int usado[2*MAXN];
    fr(i, n) usado[i] = 0;

    int menor = 0, maior = 0;

    fr(i, n){
        if(r[i].s < x){
            gasto+=r[i].f;
            usado[i] = 1;
            menor++;
        }
        else if(r[i].f > x){
            gasto+=r[i].f;
            usado[i] = 1;
            maior++;
        }
    }

    int i = 0;
    while(i < n && menor < n/2){
        if(usado[i] == 0){
            usado[i] = 1;
            gasto+=r[i].f;
            menor++;
        }

        i++;
    }

    gasto+=(n/2 - maior)*x;

    if(gasto > s) return 0;
    else return 1;
}

int main(){
	ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        cin >> n >> s;

        r.clear();
        aux.clear();
        
        ll a, b;
        fr(i, n){
            cin >> a >> b;
            r.pb(mp(a, b));
            aux.pb(mp(b, a));
        }

        sort(r.begin(), r.end());
        sort(aux.begin(), aux.end());

        ll ini = r[n/2].f, fim = 1000000000, meio;
        while(ini < fim - 1){
            meio = (ini+fim)/2;

            if(deu(meio)){
                ini = meio;
            }
            else fim = meio;

            //cout << meio << endl;
        }

        cout << ini << endl;
    }
}
