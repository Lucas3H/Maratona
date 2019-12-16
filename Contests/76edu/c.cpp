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
        int n;
        cin >> n;

        int v[2*MAXN];
        fr(i, n) cin >> v[i];

        int ans = 2*MAXN;
        int fr[2*MAXN];
        fr(i, n+1) fr[i] = -1;

        fr(i, n){
            if(fr[v[i]] == -1) fr[v[i]] = i;
            else{
                ans = min(ans, i - fr[v[i]] + 1);
                fr[v[i]] = i;
            }
        }

        if(ans == 2*MAXN) cout << -1 << endl;
        else cout << ans << endl;
    }
}