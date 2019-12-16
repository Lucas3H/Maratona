#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define ll long long

#define MAXN 100010

int n, a, d;
char m[101][101];
int pai[101], peso[101];
ll custo;

int find(int x){
    if(pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

char join(int c, int b){
    c = find(c);
    b = find(b);

    if(c == b) {
        custo += (ll)d;
        return 'd';
    }
    if(peso[c] < peso[b]) swap(c, b);

    pai[b] = c;
    peso[c] += peso[b];

    return '0';
}

int main(){
		ios::sync_with_stdio(false);
    cin >> n;
    cin >> d >> a;
    frr(i, n){
        pai[i] = i;
        peso[i] = 1;
    }

    char aux;
    frr(i, n){
        fr(j, i-1) cin >> aux;

        for(int j = i; j<= n; j++){
            cin >> aux;
            if(aux == '1') m[i][j] = join(i, j);
            else m[i][j] = '0';

            m[j][i] = m[i][j];
        }
    }

    frr(i, n-1){
        if(find(i) == find(i+1)) continue;

        char k = join(i, i+1);
        m[i][i+1] = 'a';
        m[i+1][i] = 'a';
        custo += (ll)a;
    }

    cout << custo << endl;
    frr(i, n){
        frr(j, n) cout << m[i][j];

        cout << endl;
    }
}
