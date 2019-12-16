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

int memo[(1 << 20)];
int n, k;
int m[22][22];
        
int dp(int mask, int posDavez){
    if(mask == (1 << k) - 1) return 0;
    if(memo[mask] != -1) return memo[mask];

    int ans = MAXN*20;

    fr(letra, k){
        if((mask & (1 << letra)) != 0) continue;
        
        int plus = dp((mask | (1 << letra)), posDavez+1);

        fr(letraDavez, k){
            if(letraDavez == letra) continue;

            if(((1 << letraDavez) & mask) == 0) plus -= m[letra][letraDavez]*posDavez;
            else plus += m[letra][letraDavez]*posDavez;
        }

        ans = min(ans, plus);
    }

    return memo[mask] = ans;
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n >> k;

    mem(memo, -1);

    string s;
    cin >> s;

    mem(m, 0);

    fr(i, n-1){
        m[s[i] - 'a'][s[i + 1]-'a']++;
        m[s[i+1] - 'a'][s[i] - 'a']++;
    }
/*
    fr(i, k){
        fr(j, k) cout << i << " " << j<< " " << m[i][j] << endl;
    }
*/
    cout << dp(0, 0) << endl;

//    fr(i, 8) cout << i << " " << memo[i] << endl;
}
