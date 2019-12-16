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

#define MAXN 1000010
#define MOD 1000000007

int trie[2][6*MAXN];
int fr[2][6*MAXN];

int vtx = 1;
void add(int v, int idx, int node){
    if(idx == 30) return;

    int &i = trie[(v/(1 << (29 - idx)))%2][node];

    if(i == -1) i = vtx++;

    fr[(v/(1 << (29 - idx)))%2][node]++;

    add(v, idx+1, i);
}

void remove(int v, int idx, int node){
    if(idx == 30) return;

    int &i = trie[(v/(1 << (29 - idx)))%2][node];

    remove(v, idx+1, i);
    fr[(v/(1 << (29 - idx)))%2][node]--;

    if(fr[(v/(1 << (29 - idx)))%2][node] == 0) i = -1;
}

int search(int v, int idx, int node){
    if(idx == 30) return 0;

    int &i = trie[(v/(1 << (29 - idx)))%2][node];

    if(i == -1) {
        if(trie[1 - (v/(1 << (29 - idx)))%2][node] == -1) cout << "FODEO! " << idx << endl;
        return search(v, idx+1, trie[1 - (v/(1 << (29 - idx)))%2][node]);
    }
    else {
        return (1 << (29 - idx)) + search(v, idx+1, i);
    }
}

int main(){
	ios::sync_with_stdio(false);

    int q;
    cin >> q;

    mem(trie, -1);

    add(0, 0, 0);

    while(q--){
        char op;
        ll val;
        cin >> op >> val;

        if(op == '+') add(val, 0, 0);
        else if(op == '-') remove(val, 0, 0);
        else {
//            cout << val << " OLOKO " <<endl;
            cout << search((1 << 30) - 1 - val, 0, 0) << endl;
        }
    }


}
