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

int monster[2*MAXN];
int nd[8*MAXN];
pii her[2*MAXN];

void build(int i, int l, int r){
    if(l == r) nd[i] = her[l].s;
    else{
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);

        nd[i] = max(nd[2*i], nd[2*i+1]);
    }
}

int query(int i, int l, int r, int ql, int qr){
    if(l > qr || ql > r) return 0;
    else if(ql <= l && r <= qr) return nd[i];
    else{
        int mid = (l+r)/2;

        return max(query(2*i, l, mid, ql, qr), query(2*i+1, mid+1, r, ql, qr) );
    }
}

int main(){
	ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        frr(i, n) cin >> monster[i];

        int m;
        cin >> m;

        int maximo[2*MAXN];
        fr(i, n+1)maximo[i] = 0;

        int en, po;
        frr(i, m) {
            cin >> po >> en;
            her[i] = mp(en, po);

            mx(maximo[en], po);
        }

        frm(i, n) mx(maximo[i], maximo[i+1]);

        int j = 1;

        int days = 0;
        int atual = 0;
        int maior = MOD;
        int deu = 1;
        int Q = maximo[1];

        frr(i, n){
            int q = maximo[i - atual];
            if(q < monster[i] || q < maior){
                atual = i-1;

                if(Q < monster[i]){
                    deu = 0;
                    break;
                }

                maior = monster[i];
            }
            else {
                //cout << i << endl;
                maior = max(monster[i], maior);
            //    cout << endl << " I " << i << endl;
                days++;
            }
        }

        if(deu) cout << n - days << endl;
        else cout << -1 << endl;
    }
}
