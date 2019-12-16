#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

// Ver https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/kmp.html
// Usa-se dfa ou lps

// lps[a][b] é o comprimento do maior prefixo de pat[0..j] que é sufixo de pat[0..j-1]+a
int lps[50][MAXN];

void LPS(int alfa, int length, string pat){
    int restart = 0;

    lps[pat[0] - 'a'][0] = 1;
    for(int i = 1; i < length; i++){
        for(int j = 0; j < alfa; j++) lps[j][i] = lps[j][restart];

        lps[pat[i] - 'a'][i] = i + 1;
        restart = lps[pat[i] - 'a'][restart];
    }
}

int main(){
	ios::sync_with_stdio(false);

    string s;
    cin >> s;

    LPS(26, s.size(), s);

    fr(i, s.size()) cout << s[i] <<" ";
    cout << endl;
    fr(i, 5){
        fr(j, s.size()) cout << lps[i][j] << " ";
        cout << endl;
    }

}
