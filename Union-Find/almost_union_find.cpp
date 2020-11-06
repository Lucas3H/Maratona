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

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int n, q;

int pai[2*MAXN], peso[2*MAXN];
ll  sum[2*MAXN];

int find(int x){
    if(pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(peso[a] < peso[b]) swap(a, b);

    pai[b] = a;
    peso[a]+=peso[b];
    sum[a]+=sum[b];
}

int main(){
	ios::sync_with_stdio(false);

    while(cin >> n >> q){
        frr(i, n){
            pai[i] = i + n;
            pai[i + n] = i + n;
            sum[i+n] = (ll)i;
            peso[i+n] = 1;
        }

        int a, b, c;
        while(q--){
            cin >> a >> b;

            if(a == 1){
                cin >> c;
                join(b, c);
            }
            else if(a == 2){
                cin >> c;

                int p = find(b);
                c = find(c);

                pai[b] = c;
                sum[c]+=(ll)b;
                peso[c]++;

                sum[p] -= (ll)b;
                peso[p]--;
            }
            else cout << peso[find(b)] << " " << sum[find(b)] << endl;
        }
    }
}
