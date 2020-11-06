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

int main(){
    int t;

    cin >> t;

    int n;

    vector<int> v[MAXN];   

    while(t--){
        int n;

        pq<ll , vector<ll>, greater<ll>> disponivel;

        scanf("%d", &n);
  
        fr(i, n) v[i].clear();

        int m, p;

        fr(i, n){
            scanf("%d %d", &m, &p);
            v[m].pb(p);
        }

        int comprado = 0, passado = 0;
        ll ans = 0;

        frm(i, n){

            passado += v[i].size();

            fr(j,v[i].size()) disponivel.push((ll)v[i][j]);
       
            int l = i - n + passado - comprado;

            if(l > 0){
                for(int j = 0; j < l; j++){
                    ans+=(ll)disponivel.top();
                    disponivel.pop();
                }
                comprado = i - (n - passado);
            }
        }

        printf("%lld\n", ans);
    }
}