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

ll specials[MAXN];
ll n, m, k;

// Recebo o fim da págian que estou olhando e o
// índice do primeiro que não removi
ll func(ll fim_page, ll ini_specials){
    if(ini_specials == m) return 0;

    ll remov = 0;

    while(ini_specials < m && specials[ini_specials] <= fim_page){
        ini_specials++;
        remov++;
    }

    // Se não removi nada vou pra página do primeiro especial que não removi
    if(remov == 0) return func(min( ( (specials[ini_specials] - fim_page-1)/k + 1)*k
     + fim_page, n), ini_specials);

    else return 1 + func(min(fim_page + remov, n), ini_specials);
}

int main(){
		ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    fr(i, m) cin >> specials[i];

    cout << func(k, 0) << endl;
}
