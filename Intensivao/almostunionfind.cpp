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

int pai[MAXN], peso[MAXN];
ll soma[MAXN];

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
    soma[a] += soma[b];
}

void change(int a, int b){
    b = find(b);
    int k = find(a);

    if(k == b) return;

    soma[k] -= (ll)a;
    peso[k]--;

    pai[a] = b;
    soma[b] += (ll)a;
    peso[b]++;
}

int main(){
		ios::sync_with_stdio(false);

    int n, m;

    while(cin >> n >> m){

    frr(i, n){
        pai[i] = n + i;
        peso[i] = 1;
        soma[i] = (ll)i;
    }

    for(int i = n + 1; i <= 2*n; i++){
        pai[i] = i;
        peso[i] = 1;
        soma[i] = (ll)i - (ll)n;
    }

    fr(i, m){
        int x, y, z;
        cin >> x;

        if(x == 1){
            cin >> y >> z;
            join(y, z);
        }
        else if(x == 2){
            cin >> y >> z;
            change(y, z);
        }
        else{
            cin >> y;
            y = find(y);

            cout << peso[y] << " " << soma[y] << endl;
        }
    }
  }
}
