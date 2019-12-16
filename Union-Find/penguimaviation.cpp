// Problem: http://acm.timus.ru/problem.aspx?space=1&num=1709

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
#define f first
#define s second

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int m[110][110], pai[110], peso[110];
char ans[110][110];
int n, A, d;
ll total;

int find(int x){
    if(pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int a, int b, int faz){
    int a0 = a;
    a = find(a);
    int b0 = b;
    b = find(b);

    if(a == b){
        m[a0][b0] = 0;
        m[b0][a0] = 0;

        ans[a0][b0] = 'd';
        ans[b0][a0] = 'd';
        total += (ll)d;

        return;
    }
    if(peso[a] < peso[b]) swap(a, b);

    if(faz){
        ans[a][b] = 'a';
        ans[b][a] = 'a';

        total += (ll)A;
    }

    pai[b] = a;
    peso[a] += peso[b];
}

int main(){
	ios::sync_with_stdio(false);
    cin >> n >> d >> A;

    frr(i, n){
        frr(j, n) ans[i][j] = '0';
    }

    char p;
    frr(i, n){
        frr(j, n) {
            cin >> p;
            m[i][j] = p - '0';
        }
    }

    frr(i, n) {
        pai[i] = i;
        peso[i] = 1;
    }

    frr(i, n){
        for(int j = i+1; j <= n; j++){
            if(m[i][j] == 1) join(i, j, 0);
        }
    }

    frr(i, n-1){
        if(find(i+1) != find(i)) join(i, i+1, 1);
    }

    cout << total << endl;
    frr(i, n){
        frr(j, n) cout << ans[i][j];
        cout << endl;
    }
}
