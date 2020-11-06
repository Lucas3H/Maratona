#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back

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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

#define vtx first
#define cost second

ll n, m;
queue<pii> in_d[MAXN], out_d[MAXN];
vector<pii> in_ans[MAXN], out_ans[MAXN];

void read(){
	cin >> n >> m;

	fr(i, m){
		ll v1, v2, c;
		cin >> v1 >> v2 >> c;

		if(v1 > v2){
			in_d[v2].push(mp(v1, c));
		}
		else{
			out_d[v1].push(mp(v2, c));
		}
	}
}

void ajeitar(ll ind){
	while(in_d[ind].empty() == 0 && out_d[ind].empty() == 0){
		pii a = in_d[ind].front(), b = out_d[ind].front();
		
		in_d[ind].pop();
		out_d[ind].pop();
	
		ll minimo = min(a.cost, b.cost);
		
		if(a.vtx > b.vtx){
			if(b.vtx > ind){
				in_d[b.vtx].push(mp(a.vtx, minimo));
			}
			else if(a.vtx > ind){
				out_d[a.vtx].push(mp(b.vtx, minimo));
			}
			else{
				in_ans[b.vtx].pb(mp(a.vtx, minimo));
			}
		}
		else{
			if(a.vtx > ind){
				out_d[a.vtx].push(mp(b.vtx, minimo));
			}
			else if(b.vtx > ind){
				in_d[b.vtx].push(mp(a.vtx, minimo));
			}
			else{
				out_ans[a.vtx].pb(mp(b.vtx, minimo));
			}
		}

		if(a.second == b.second) continue;
		else if(a.cost > b.cost){
			a.cost -= b.cost;
			in_d[ind].push(a);
		}
		else{
			b.cost -= a.cost;
			out_d[ind].push(b);
		}
	}

	while(in_d[ind].empty() == 0){
		pii a = in_d[ind].front();
		in_d[ind].pop();

		if(a.vtx > ind){
			pii novo = mp(ind, a.cost);
			out_d[a.vtx].push(novo);
		}
		else if(a.vtx < ind){
			pii novo = mp(ind, a.cost);
			out_ans[a.vtx].pb(novo);
		}
	}

	while(out_d[ind].empty() == 0){

		pii a = out_d[ind].front(); 

		out_d[ind].pop();

		if(a.vtx > ind){
			pii novo = mp(ind, a.cost);
			in_d[a.vtx].push(novo);
		}
		else if(a.vtx < ind){
			pii novo = mp(ind, a.cost);
			in_ans[a.vtx].pb(novo);
		}
	}
}

ll tot = 0;

void ajeitar_ans(ll ind){
	
	if(in_ans[ind].size() > 0){ 
	vector<pii> ans_in;

	sort(in_ans[ind].begin(), in_ans[ind].end());

	fr(i, in_ans[ind].size() - 1){
		if(in_ans[ind][i].vtx == in_ans[ind][i + 1].vtx){
			in_ans[ind][i + 1].cost += in_ans[ind][i].cost;
		}
		else{
			ans_in.pb(in_ans[ind][i]);
		}
	}

	ans_in.pb(in_ans[ind][in_ans[ind].size() - 1]);
	in_ans[ind] = ans_in;

	tot+=in_ans[ind].size();
	}
	if(out_ans[ind].size() > 0){
	vector<pii> ans_out;

	sort(out_ans[ind].begin(), out_ans[ind].end());

	fr(i, out_ans[ind].size() - 1){
		if(out_ans[ind][i].vtx == out_ans[ind][i + 1].vtx){
			out_ans[ind][i + 1].cost += out_ans[ind][i].cost;
		}
		else{
			ans_out.pb(out_ans[ind][i]);
		}
	}

	ans_out.pb(out_ans[ind][out_ans[ind].size() - 1]);

	out_ans[ind] = ans_out;


	tot+=out_ans[ind].size();
	}
}

int main(){
	ios::sync_with_stdio(false);

	read();

	frr(i, n){
		ajeitar(i);
/*
		cout <<i << "------------\n";
		frr(i, n){
			cout << in_d[i].size() << " " << out_d[i].size() << endl;
		}
	*/}

	frr(i, n){
		ajeitar_ans(i);
	}

	cout << tot << endl;

	frr(i, n){

		for(auto x: in_ans[i]){
			cout << x.vtx << " " << i << " " << x.cost << endl;
		}

		for(auto x: out_ans[i]){
			cout << i << " " << x.vtx << " " << x.cost << endl;
		}
	}
}
