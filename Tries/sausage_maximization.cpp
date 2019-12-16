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

#define db cout << "\nDebug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int trie[2][40*MAXN];
int vtc = 1;

void add(ll v, int idx, int node){
    if(idx == -1) return;

    int &i = trie[(v >> idx)%2][node];

    if(i == -1) i = vtc++;

    add(v, idx-1, i);
}

ll search(ll v, int idx, int node){
    if(idx == -1) return 0;

    int &i = trie[(v >> idx)%2][node];

    if(i == -1){
        if((v >> idx)%2 == 0) return ((ll)1 << idx) + search(v, idx-1, trie[1 - (v >> idx)%2][node]);
        else return search(v, idx-1, trie[1 - (v >> idx)%2][node]);
    }
    else{
        if((v >> idx)%2 == 1) return ((ll)1 << idx) + search(v, idx-1, trie[(v >> idx)%2][node]);
        else return search(v, idx-1, trie[(v >> idx)%2][node]);
    }
}

int main(){
	ios::sync_with_stdio(false);

    mem(trie, -1);

    int n;
    cin >> n;

    ll v[MAXN], tot = 0, maximo;
    fr(i, n){
        cin >> v[i];
        tot = tot^v[i];

        maximo = max(maximo, tot);
    }

    ll atu = 0;
    add((ll)0, 39, 0);

    fr(i, n){
        atu = atu^v[i];
        add(atu, 39, 0);

        //cout << "atu : " << atu <<  "| xor: " << (tot^atu) << " | procurar: " << ( ( ((ll)1 << 40) - 1)^(tot^atu)) << " " << search( ( ( ((ll)1 << 40) - 1)^(tot^atu)) , 39, 0) << endl;
        maximo = max(maximo, (tot^atu^search(( ( ((ll)1 << 40) - 1)^(tot^atu)), 39, 0)) );
    }

    cout << maximo << endl;
}
