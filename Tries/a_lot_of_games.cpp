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

int n, k;
int tries[26][MAXN];
int tipo[MAXN];

int vtc = 1;

/*
    1 = Posição perdedora sempre
    2 = Posicao vencedora sempre
    3 = Posicao SuperVencedora
    4 = Posicao SuperPerdedora
*/

void add(string s, int idx, int node){
    if(idx == s.size()) return;

    int &i = tries[s[idx] - 'a'][node];

    if(i == -1) i = vtc++;

    add(s, idx + 1, i);
}

int main(){
	ios::sync_with_stdio(false);

    mem(tries, -1);

    cin >> n >> k;

    string s;
    fr(i, n){
        cin >> s;

        add(s, 0, 0);
    }

    frm(i, vtc){
        int t[5];

        fr(j, 5) t[j] = 0;

        fr(j, 26){
            if(tries[j][i] == -1) continue;

            t[tipo[tries[j][i]]] = 1;
        }
/*
        frr(j, 4) cout << t[j] << " ";
        cout << endl;
*/
        if(t[1] == 0 && t[2] == 0 && t[3] == 0 && t[4] == 0) tipo[i] = 1;
        else if(t[4] == 1) tipo[i] = 3;
        else if(t[1]*t[2] == 1) tipo[i] = 3;
        else if(t[1] == 1) tipo[i] = 2;
        else if(t[2] == 1) tipo[i] = 1;
        else tipo[i] = 4;

        //cout << i << " " << tipo[i] << endl;
    }

    if(tipo[0] == 3) cout << "First" << endl;
    else if(tipo[0] == 4) cout << "Second" << endl;
    else if(tipo[0] == 1) cout << "Second" << endl;
    else{
        if(k%2 == 1) cout << "First" << endl;
        else cout << "Second" << endl;
    }
}
