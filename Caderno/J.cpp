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
vector<int> adj[MAXN];
int prox[MAXN], pr[MAXN];
int maxl;
int ancestor[MAXN][MAXL];

void nse(int v[], int n, int ret[]){
    for(int i = 0; i < n; i++){
        ret[i] = n + 1;
    }

    stack<int> s;

    for(int i = 0; i < n; i++){
        while(!s.empty() && v[s.top()] > v[i]){
            ret[s.top()] = i;
            s.pop();
        }

		s.push(i);
    }
}

void dfs(int vtx){
	ancestor[vtx][0] = prox[vtx];
    for(int i = 1; i <= maxl; i++){
        ancestor[vtx][i] = ancestor[ancestor[vtx][i-1]][i-1];
    }

    for(int u: adj[v]){
        if(!pr[u]) dfs(u, v);
    }
}

int find(int pos, int val){
	int ret = n + 1;

	for (int i = maxl; i >= 0; --i) {
        if (v[ancestor[pos][i]] >= val/*!is_ancestor(ancestor[a][i], b)*/)
            pos = ancestor[pos][i];
    }

    return pos;
}

void build(){
	maxl = log(n);

	nse(v, n, prox);
	frr(i, n){
		adj[prox[i]].pb(i);
	}

	dfs(n + 1);
}

int main(){
	scanf("%lld %lld", &n,&q);

	frr(i, n){
		scanf("%lld", v + i);
	}

	build();

	fr(i,q){
		ll val,left,right;

		scanf("%lld %lld %lld",&val,&left,&right);

		//dbg(query(1,1,n,2,2));

		ll p = left;
		while(p <= right){
			//dbg(p);
			val = val%v[p];
			p = find(p,val);

		}

		printf("%lld\n",val);
	}

}
