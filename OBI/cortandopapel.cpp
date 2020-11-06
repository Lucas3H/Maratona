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

int main(){
		ios::sync_with_stdio(false);
    int n, a[MAXN];
    cin >> n;
    fr(i, n) cin >> a[i];
    a[n] = 0;

    int ini[MAXN], fim[MAXN], j = 0;
    frr(i, n){
        if(a[i] < a[i-1]){
            ini[j] = a[i];
            fim[j] = a[i-1];
            j++;
        }
    }

    vector<pii> v;

    fr(i, j){
        v.pb(mp(ini[i], 1));
        v.pb(mp(fim[i], 0));
    }

    sort(v.begin(), v.end());

    int m = 1, sum = 0;

    fr(i, v.size()){
        if(v[i].second == 1){
            sum++;
            m = max(m, sum);
        }
        else sum--;
    }

    cout << m + 1 << endl;
}
