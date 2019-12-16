// https://www.urionlinejudge.com.br/judge/en/problems/view/2658

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

int n, q;

int nd[4*MAXN][9];
int lz[4*MAXN];

void build(int i, int l, int r){
    if(l == r) nd[i][1] = 1;
    else{
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);

        nd[i][1] = (r - l + 1);
    }
}

void push(int i, int l, int r){
    if(lz[i] == 0) return;

    int aux[9];
    fr(j, 9) aux[j] = nd[i][j];
    fr(j, 9) nd[i][(j + lz[i])%9] = aux[j];

    if(l < r){
        lz[2*i]+=lz[i];
        lz[2*i+1]+=lz[i];
    }

    lz[i] = 0;
}

void update(int i, int l, int r, int ql, int qr, int v){
    push(i, l, r);

    if(ql > r || l > qr) return;
    else if(ql <= l && r <= qr) {
        lz[i]+=v;
        push(i, l, r);
    }
    else{
        int mid = (l+r)/2;

        update(2*i, l, mid, ql, qr, v);
        update(2*i + 1, mid+1, r, ql, qr, v);

        fr(j, 9) nd[i][j] = nd[2*i][j] + nd[2*i+1][j];
    }
}

int ans[9];
void query(int i, int l, int r, int ql, int qr){
    push(i, l, r);

    if(ql > r || l > qr) return;
    else if(ql <= l && r <= qr){
        //cout << "ok " << l << " " << r << endl;
        fr(j, 9) ans[j] += nd[i][j];
    }
    else{
        int mid = (l+r)/2;

        query(2*i, l, mid, ql, qr);
        query(2*i+1, mid+1, r, ql, qr);
    }
}

int main(){
	ios::sync_with_stdio(false);
    cin >> n >> q;

    build(1, 1, n);

    int a, b;
    while(q--){
        fr(i, 9) ans[i] = 0;
        cin >> a >> b;

        query(1, 1, n, a+1, b+1);

        int maior = 0;

        //cout << "ans" << endl;
        fr(i, 9) {
            if(ans[i] >= ans[maior]) maior = i;
            //cout << ans[i] << " ";
        }
    //    db
        //cout << maior << endl;

        update(1, 1, n, a+1, b+1, maior);
/*
        frr(j, n){
            fr(i, 9) ans[i] = 0;

            query(1, 1, n, j, j);

            fr(i, 9){
                if(ans[i] > 0){
                    cout << i << " ";
                    continue;
                }
            }
        }
*/
    }

    frr(j, n){
        fr(i, 9) ans[i] = 0;

        query(1, 1, n, j, j);

        fr(i, 9){
            if(ans[i] > 0){
                cout << i << endl;
                continue;
            }
        }
    }
}
