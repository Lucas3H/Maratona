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
        int n, k;
        cin >> n >> k;

        int usado[5*MAXN];
        ll ans = 0;

        vector<pair<ll, pii>> e;

        frr(i, n) usado[i] = 0;

        ll v1, v2, w;
        fr(i, n-1){
            cin >> v1 >> v2 >> w;
            e.pb(mp(w, mp(v1, v2)));
        }

        sort(e.begin(), e.end());

        frm(i, n-1){
            if(usado[e[i].s.f] < k && usado[e[i].s.s] < k){
                usado[e[i].s.f]++;
                usado[e[i].s.s]++;
                ans += e[i].f;
            }
        }

        cout << ans << endl;
    }
}
