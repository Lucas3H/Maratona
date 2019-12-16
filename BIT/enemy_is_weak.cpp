// https://codeforces.com/problemset/problem/61/E

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

#define MAXN 1000010
#define MOD 1000000007

int n, v[MAXN], bit[MAXN], aux[MAXN];
map<int, int> m;

void update(int i, int val){
    while(i <= n){
        bit[i]+=val;
        i+=i&(-i);
    }
}

int query(int i){
    int sum = 0;
    while(i > 0){
        sum+=bit[i];
        i-=i&(-i);
    }

    return sum;
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n;
    frr(i, n) {
        cin >> v[i];
        aux[i] = v[i];
    }

    sort(v+1, v+n+1);
    m[0] = 0;
    v[n+1] = 1000000001;
    fr(i, n+2) m[aux[i]] = i;

    ll ans = 0;

    frr(i, n){
        ll x = (ll)query(m[v[i]]);
        ll y = (ll)query(n);

        ans += (y - x)*((ll)m[v[i]] - x - (ll)1);

        update(m[v[i]], 1);
    }

    cout << ans << endl;
}
