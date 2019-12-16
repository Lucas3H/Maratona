// https://codeforces.com/contest/597/problem/C

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

ll n, k;
ll bit[MAXN][12];
ll aux;

void update(ll i, ll val, ll rep){
    while(i <= n){
        bit[i][rep] += val;
        i += i&(-i);
    }
}

ll query(ll i, ll rep){
    ll sum = 0;

    while(i > 0){
        sum+=bit[i][rep];
        i-=i&(-i);
    }

    return sum;
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n >> k;


    frr(i, n){
        cin >> aux;
        update(aux, (ll)1, (ll)1);

        for(ll j = 1; j <= k; j++) update(aux, query(aux-1, j), j+1);
    }

    cout << query(n, k+1) << endl;
}
