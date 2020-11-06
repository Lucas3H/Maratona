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

#define MAXN 1010
#define MOD 1000000007

int pai[MAXN], peso[MAXN], v[MAXN];

int find(int x){
	if(pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b) return;

	if(peso[a] > peso[b]) swap(a, b);

	pai[a] = b;
	peso[b]+=a;

	return;
}

int main(){
		ios::sync_with_stdio(false);
		int n, m;
		cin >> n >> m;

		frr(i, n){
			pai[i] = i;
			peso[i] = 1;
			v[i] = 10000 - i;
		}

		int t, l, r;

		vector<pii> a, b;

		fr(i, m){
			cin >> t >> l >> r;

			if(t == 1) a.pb(mp(l, r));
			else b.pb(mp(l, r));
		}

		fr(i, a.size()){
			for(int j = a[i].first; j < a[i].second; j++){
				join(j, j+1);
			//	cout << "OKOK " << a[i].first << " " << a[i].second << endl;
				//cout << j << " " << j+1 << endl;
			}
		}

		fr(i, b.size()){
			l = find(b[i].first);
			r = find(b[i].second);

			if(l == r){
				cout << "NO" << endl;
				return 0;
			}

		//	cout << l << " " << r << endl;

		}

		cout << "YES" << endl;


		frr(i, n) cout << v[find(i)] << " ";
}
