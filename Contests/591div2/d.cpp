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
        int n;
        cin >> n;

        int a[3*MAXN];
        int pri[3*MAXN];
        int ult[3*MAXN];

        set<int> aux;

        fr(i, n) {
            cin >> a[i];
            aux.insert(a[i]);
        }

        vector<int> ap;
        for(auto x: aux){
            ap.pb(x);
            pri[x] = -1;
            ult[x] = -1;
        }

        fr(i, n){
            if(pri[a[i]] == -1) pri[a[i]] = i;
            ult[a[i]] = i;
        }



        int certo[3*MAXN];

        for(int i = 0; i < ap.size(); i++) certo[i] = 0;

        for(int i = 1; i < ap.size(); i++){
            //cout << pri[ap[i]] << " " << ult[ap[i-1]] << endl;
            if(pri[ap[i]] > ult[ap[i-1]]) certo[i] = 1;

            //cout << certo[i] << " ";
        }

        int maior = 0;
        int i = 1, j = 1;
        while(i < ap.size()){
            if(certo[i] == 1){
                int tam = 1;
                j = i + 1;
                while( j < ap.size() && certo[j] == 1){
                    tam++;
                    j++;
                }

                if(tam > maior) maior = tam;
            }
            i++;
        }

        cout << maior << endl;

        cout << ap.size() - maior - 1 << endl;

    }
}
