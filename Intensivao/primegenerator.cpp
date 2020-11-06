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

int v[MAXN];

int main(){
		ios::sync_with_stdio(false);
    int tests;
    cin >> tests;

    int prime[MAXN];
    vector<int> p;
    for(int i = 2; i < MAXN; i++){
        if(prime[i] == 0){
            for(int j = 2*i; j < MAXN; j += i) prime[j] = 1;
            p.pb(i);
        }
    }

    while(tests--){
        int n, m;
        cin >> n >> m;

        mem(v, 0);

        fr(i, p.size()){
            int r = n%p[i];

						for(int j = (p[i] - r)%p[i]; j < m - n + 1; j += p[i]){
								if(p[i]!= j+n) v[j] = 1;
            }
        }

				if(n == 1){
						frr(i, m - n){
								if(v[i] == 0) cout << i + n << endl;
						}
						continue;
				}
        fr(i, m - n + 1){
            if(v[i] == 0) cout << i + n << endl;
        }
    }
}
