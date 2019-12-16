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
        string s, t;
        cin >> s >> t;

        int a[30], b[30];
        fr(i, 26){
            a[i] = 0;
            b[i] = 0;
        }

        fr(i, s.size()) a[s[i] - 'a']++;
        fr(i, t.size()) b[t[i] - 'a']++;

        int da = 0;
        fr(i, 26){
            if(a[i]>0 && b[i] > 0){
                da = 1;
                break;
            }
        }

        if(da) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
