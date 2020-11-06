// 
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
#define MAXA 1000010
/*
	Essa estrutura de dados faz a mesma coisa que a Segtree. Mas aqui, o problema a ser resolvido é 
	o seguinte: dado um Array v e um intervalo [l, r], quantos elementos distintos há nesse intervalo.
	Todas as queries são feita em O((N + Q)*sqrt(N)). Não pode ser usada quando há update.
*/

struct Query{
	int l, r, idx;
};

ll n, len;
vector<int> a;

void build(){
	ll aux;
	a.clear();

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> aux;
		a.push_back(aux);
	}

	len = (int) sqrt (n + .0) + 1; 
}

bool comp(Query a, Query b){
	if((a.l)/len == (b.l)/len) return a.r < b.r;
	else return (a.l)/len < (b.l)/len;
}

void queryResults(int n_queries){
	vector<Query> q;
	Query aux;
	fr(i, n_queries){
		cin >> aux.l >> aux.r;
		aux.idx = i;
		q.push_back(aux); 
	}

	sort(q.begin(), q.end(), comp);
	
	int curL = 0, curR = 0; 
    set<ll> curSet; 

	ll ans[MAXN];
	ll app[MAXN];
	fr(i, MAXA+1) app[i] = 0;

	fr(i, n_queries){
		int L = q[i].l, R = q[i].r;
		
		while (curL > L) { 
			app[a[curL-1]]++;
            if(app[a[curL - 1]] == 1) curAns++; 
            curL--; 
        } 
        while (curR <= R) { 
			app[a[curR]]++;
            if(app[a[curR]] == 1) curAns++;
            curR++; 
        }

		while (curL < L) { 
			app[a[curL]]--;
            if(app[a[curL]] == 0) curAns--;
            curL++; 
        } 

		while (curR > R+1) { 
			app[a[curR - 1]]--;
            if(app[a[curR - 1]] == 0) curAns--;
            curR--; 
        }  

		ans[q[i].idx] = curAns;
	}
}

int main(){
	ios::sync_with_stdio(false);


}
