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

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;

        int u = 0, z = 0, odd = 0;
        string s;
        fr(i, n){
            cin >> s;
            if(s.size()%2 == 1) odd = 1;

            fr(j, s.size()){
                if(s[j] == '1')u++;
                else z++;
            }
        }

        if(odd){
            cout << n << endl;
            continue;
        }

        if(u%2 == 0){
            cout << n << endl;
        }
        else cout << n-1 << endl;

    }
}
