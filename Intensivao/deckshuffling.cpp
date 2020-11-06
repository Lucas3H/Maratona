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

#define MAXN 200010

int n, k;
int a[MAXN];
int pai[MAXN], peso[MAXN];

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
    peso[a] += peso[b];
}

int main(){
		ios::sync_with_stdio(false);

    cin >> n;
    frr(i, n) cin >> a[i];

    frr(i, n){
        pai[i] = i;
        peso[i] = 1;
    }

    cin >> k;
    int p[MAXN];

    frr(i, k){
        frr(j, n){
            cin >> p[j];

            join(j, p[j]);
        }
    }

    int x;
    cin >> x;

    frr(i, n) {
      if(a[i] == x){
          x = i;
          break;
      }
    }

    if(find(x) == find(1)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
