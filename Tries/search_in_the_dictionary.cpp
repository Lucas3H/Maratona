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

#define MAXN 500001
#define MOD 1000000007

int trie[MAXN][26];
bool isEnd[MAXN];

int nd = 1;
int n;

char ans[22];

void add(string s, int idx, int node){
    if(idx == s.size()){
        isEnd[node] = 1;
        return;
    }
    int &i = trie[node][s[idx] - 'a'];

    if(i == -1) i = nd++;

    add(s, idx + 1, i);
}

int search(string s, int idx, int node){
    if(idx == s.size()) return node;

    int &i = trie[node][s[idx] - 'a'];

    if(i == -1) return -1;

    else return search(s, idx+1, i);

}

void build(int node, string s, int tam){
    if(isEnd[node] && tam > 0){
        cout << s;
        fr(i, tam) cout << (char)(ans[i] + 'a');
        cout << endl;
    }

    fr(i, 26){
        if(trie[node][i] > -1){
            ans[tam] = i;
            build(trie[node][i], s, tam + 1);
        }
    }
}

int main(){
	ios::sync_with_stdio(false);

    mem(trie, -1);
    mem(isEnd, 0);

    string s;

    nd = 1;
    cin >> n;

    fr(i, n){
        cin >> s;
        add(s, 0, 0);
    }

    int k;
    cin >> k;

    frr(i, k){
        cout << "Case " << i << "#:" << endl;
        cin >> s;

        int na = search(s, 0, 0);

        if(na == -1) cout << "No match." << endl;
        else build(na, s, 0);
    }
}
