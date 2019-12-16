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

#define MAXN 100010
#define MOD 1000000007

int v[11][100010];
int isEnd[100010];

int vtx;
int n;

int add(string s, int idx, int node, int nw){
    if(isEnd[node]) return 1;

    if(idx == s.size()){
        isEnd[node] = 1;

        if(nw){
        //    cout << "pppç " << s << endl;
            return 0;
        }
        else return 1;
    }

    int &i = v[s[idx] - '0'][node];

    if(i == -1) {
        nw = 1;
        i = vtx++;
    }
    return add(s, idx+1, i, nw);
}
int main(){
	ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        vtx = 1;
        mem(isEnd, 0);
        mem(v, -1);

        cin >> n;
        string s;

        int ok = 0;

        fr(i, n){
            cin >> s;

            //cout << t << " " << add(s, 0, 0, 0) << endl;

            if(add(s, 0, 0, 0)) ok = 1;
        }

        if(ok) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
