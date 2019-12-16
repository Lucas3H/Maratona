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

#define MAXN 100010
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);
    int q;
    cin >> q;

    while(q--){
        int h, n;
        cin >> h >> n;

        int p[2*MAXN];
        fr(i, n) cin >> p[i];

        p[n] = 0;

        int ans = 0, usei = 0;

        int ini[MAXN], fim[MAXN];

        int tot = 0;

        ini[0] = p[0];

        fr(i, n){
            if(p[i+1] == (p[i] - 1)) continue;
            if(p[i+1] != p[i] - 1){
                fim[tot++] = p[i];
                ini[tot] = p[i+1];
            }
        }

        fr(i, tot+1) cout << ini[i] << " " << fim[i] << endl;

        fim[tot] = 0;
        int aux = 0;

        fr(i, tot) {
            if(ini[i]%2 != fim[i]%2){
                fim[i] = fim[i] + 1;
                aux = 1;
            }

            if(aux == 0) ini[i+1] = ini[i+1] + 1;
            else if(fim[i] > ini[i + 1] + 2){
                ini[i+1] = ini[i + 1] + 1;
                ans++;
            }

            aux = 0;
        }


/*
        int atu = fim[0];
        int prox = 0;

        if(ini[prox]%2 == fim[prox]%2){
            atu = fim[prox];
            prox++;
        }
        else{
            atu = fim[prox] + 1;
            prox++;
        }

        while(atu > 0 && prox <= tot){

            //cout << atu << endl;

            if((atu - ini[prox]) > 2){
                ans++;
                if(ini[prox]%2 == fim[prox]%2){
                    atu = fim[prox]+1;
                    prox++;
                }
                else{
                    atu = fim[prox];
                    prox++;
                }
            }
            else if(atu - ini[prox] == 2){
                if(ini[prox]%2 == fim[prox]%2){
                    atu = fim[prox];
                    prox++;
                }
                else{
                    atu = fim[prox] + 1;
                    prox++;
                }
            }
        }
*/
        cout << ans << endl;
    }
}
