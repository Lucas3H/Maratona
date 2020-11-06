#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll n, q;
ll v[MAXN];
vector<ll> adj[MAXN];
ll prox[MAXN], pr[MAXN];
ll maxl;
ll ancestor[MAXN][MAXL];

void nse(ll v[], ll n, ll ret[]){
    for(ll i = 1; i <= n; i++){
        ret[i] = n + 1;
    }

    stack<ll> s;

    for(ll i = 1; i <= n; i++){
        while(!s.empty() && v[s.top()] > v[i]){
            ret[s.top()] = i;
            s.pop();
        }

		s.push(i);
    }
}

void dfs(ll vtx){
	pr[vtx] = 1;
	ancestor[vtx][0] = prox[vtx];
    for(ll i = 1; i <= maxl; i++){
        ancestor[vtx][i] = ancestor[ancestor[vtx][i-1]][i-1];
    }
	/*
    cout << vtx << " Oloko \n";
    fr(i, maxl + 1){
    	cout << ancestor[vtx][i] << ' ';
    }

    cout << "cabou \n";
	*/
    for(ll u: adj[vtx]){
        if(!pr[u]) dfs(u);
    }
}

ll find(ll pos, ll val){
	ll ret = n + 1;

	for (ll i = maxl; i >= 0; --i) {
        if (v[ancestor[pos][i]] > val){
            pos = ancestor[pos][i];
        }
    }

    //cout << ancestor[pos][0] << endl;

    return ancestor[pos][0];
}

void build(){
	maxl = log(n) + 1;

	nse(v, n, prox);

	frr(i, n){
		adj[prox[i]].pb(i);
	}

	prox[n+1] = n + 1;
	v[n+1] = -1;
	dfs(n + 1);
}

int main(){
	scanf("%lld %lld", &n,&q);

	frr(i, n){
		scanf("%lld", v + i);
	}

	build();

	//cout << find(1, 2) << "\n";

	fr(i,q){
		ll val,left,right;

		scanf("%lld %lld %lld",&val,&left,&right);

		//dbg(query(1,1,n,2,2));

		ll p = left;
		while(p <= right){
			//dbg(p);
			val = val%v[p];
			p = find(p,val);
			//cout << p <<" " << val << endl;

		}

		printf("%lld\n",val);
	}

}
