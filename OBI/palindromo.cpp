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

#define MAXN 2010
#define MOD 1000000007

vector<int> p[MAXN];
string s;
int n;

void achar_palindromos(){
    for(int i = 0; i < n; i++){
        p[i].pb(i);

        for(int j = 1; i - j >= 0 && i + j < n; j++){
            if(s[i+j] != s[i-j]) break;
            else p[i-j].pb(j + i);
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; (i - j) >= 0 && (i + 1 + j) < n; j++){
            if( s[i - j] != s[i + 1 + j] ) break;
            p[i - j].pb(i + j + 1);
        }
    }
}

int me[MAXN];

int dp(int ini){
    if(ini == n) return 0;
    if(me[ini] > -1) return me[ini];

    int ans = n;

    fr(i, p[ini].size()) ans = min(ans, dp(p[ini][i] + 1) + 1);

    return me[ini] = ans;
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n;
    int ts = 1;
    while(n > 0){
        cin >> s;

        fr(i, n) {
            me[i] = -1;
            p[i].clear();
        }
        achar_palindromos();

        cout << "Teste " << ts <<endl << dp(0) << endl << endl;

        cin >> n;

        ts++;
    }
/*
    fr(i, s.size()){
        cout << i << " ";
        fr(j, p[i].size()) cout << p[i][j] << " ";

        cout << endl;
    }*/
}
