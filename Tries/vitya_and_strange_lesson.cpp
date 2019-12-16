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

#define MAXN 300010
#define MOD 1000000007

int a[MAXN];

int trie[2][20*MAXN];
int tam[2][20*MAXN];

int vtc = 1;

int add(int v, int idx, int node){
    int &t = tam[(v >> idx)%2][node];
    if(idx == 0){
        if(t == 0) return ++t;
        else return 0;
    }

    int &i = trie[(v >> (idx))%2][node];
    if(i == -1) i = vtc++;

    int a = add(v, idx-1, i);

    tam[(v >> (idx))%2][node] += a;
    return a;
}

int search(int v, int idx, int node){
    if(node == -1) return 0;
    if(idx == -1) return 0;

    //cout << "v : " << v << " | idx : "<< idx << " | (v >> idx)%2 : " << (v >> idx)%2 << " | tam: " << tam[(v >> idx)%2][node] << endl;
    if(tam[(v >> idx)%2][node] == (1 << (idx) ) ){
        int &i = trie[1 - (v >> idx)%2][node];
        //cout << idx << " " << i << endl;
        return (1 << idx) + search(v, idx-1, i);
    }
    else{
        int &i = trie[(v >> idx)%2][node];
        return search(v, idx - 1, i);
    }
}


int main(){
	ios::sync_with_stdio(false);

    mem(trie, -1);
/*    fr(i, 20*MAXN){
        tam[0][i] = 1;
        tam[1][i] = 1;
    }
*/
    int n, m;
    cin >> n >> m;

    int aux;
    fr(i, n){
        cin >> aux;
        add(aux, 19, 0);
    }
    int atu = 0;
    fr(i, m){
        cin >> aux;
        atu = atu^aux;
    //    cout << atu << endl;

        cout << search(atu, 19, 0) << endl;
    }
}
