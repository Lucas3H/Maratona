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

int main(){
	ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        int ini = 0, i = 0, tam = 0;
        int ok[30];
        mem(ok, 0);

        while(i < s.size()){
            ini = i;
            tam = 1;

            i++;

            while(i < s.size() && s[i] == s[ini]){
                tam++;
                i++;
            }

            //cout << t << " " << tam << endl;

            if(tam%2 == 1) ok[s[ini]-'a'] = 1;
        }

        fr(i, 26){
            if(ok[i]) cout << (char)(i + 'a');
        }

        cout << endl;
    }
}
