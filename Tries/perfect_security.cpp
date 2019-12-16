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

int trie[2][30*MAXN];
int fr[2][30*MAXN];

int vtc = 1;

void add(int v, int idx, int node){
    if(idx == -1) return;

    int &i = trie[(v >> (idx))%2][node];

    if(i == -1) i = vtc++;
    fr[(v >> (idx))%2][node]++;

    add(v, idx - 1, i);
}

void remove(int v, int idx, int node){
    if(idx == -1) return;

    int &i = trie[(v >> idx)%2][node];
    remove(v, idx-1, i);

    fr[(v >> idx)%2][node]--;
    if(fr[(v >> idx)%2][node] == 0) i = -1;
}

int search(int v, int idx, int node){
    if(idx == -1) return 0;

    int &i = trie[(v >> idx)%2][node];

    if(i == -1) {
        if((v >> idx)%2 == 0) return (1 << idx) + search(v, idx-1, trie[1 - (v >> idx)%2][node]);
        else return search(v, idx-1, trie[1 - (v >> idx)%2][node]);
    }
    else {
        if((v >> idx)%2 == 0) return search(v, idx-1, i);
        else return (1 << idx) + search(v, idx-1, i);
    }
}

int main(){
	ios::sync_with_stdio(false);

    mem(trie, -1);

    int n;
    cin >> n;

    fr(i, n) cin >> a[i];
    int aux;
    fr(i, n){
        cin >> aux;
        add(aux, 29, 0);
    }

    int ans[MAXN];
    fr(i, n){
        ans[i] = search(a[i], 29, 0);

        remove(ans[i], 29, 0);
    }

    fr(i, n) cout << (ans[i]^a[i]) << " ";
    cout << endl;
}
