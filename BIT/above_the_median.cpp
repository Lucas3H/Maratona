// https://vn.spoj.com/problems/KMEDIAN/

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

int v[MAXN];
int bit[2*MAXN];
int n, x;

void update(int i, int val){
    while(i <= 2*n + 1){
        bit[i] += val;

        i += i&(-i);
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

    cin >> n >> x;

    int aux = 0;
    frr(i, n){
        cin >> aux;

        if(aux >= x)update(i, 1);
        else update(i, -1);

        v[i] = query(i) + n + 1;
    }

    frr(i, 2*n+1) bit[i] = 0;

    ll ans = 0;
    update(n + 1, 1);
    frr(i, n){

        ans += (ll)query(v[i]);
        update(v[i], 1);

        //cout << i << " " << ans << endl;
    }

    cout << ans << endl;
}
