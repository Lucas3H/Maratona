#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first

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

#define MAXN 2000010
#define MOD 1000000007

int g[26];
int trie[26][MAXN];

int vtc = 1, k;
int ans = 0;

string s;

void add(int ini, int fim, int idx, int node, int bad){
    if(bad + 1 - g[s[idx] - 'a'] > k) return;
    if(idx == fim+1) return;

    int &i = trie[s[idx] - 'a'][node];
    if(i == -1){
        ans++;
        i = vtc++;
    }

    add(ini, fim, idx+1, i, bad + 1 - g[s[idx] - 'a']);
}

int main(){
	ios::sync_with_stdio(false);

    cin >> s;

    mem(trie, -1)

    char o;
    fr(i, 26){
        cin >> o;
        g[i] = o - '0';
    }

    cin >> k;

    fr(i, s.size()){
        add(i, s.size() - 1, i, 0, 0);

    }

    cout << ans << endl;
}
