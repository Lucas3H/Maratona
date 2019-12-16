#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

int main(){
	int n, m, k;
	cin >> n >> m >> k;

	ll a[100010], d[100010];

	pq<tuple<int, int, int>> ativo0, inativo0;
	
	frr(i, n) cin >> a[i];

	frr(i, m){
		int l, r;
		cin >> l >> r >> d[i];

		inativo0.push(make_tuple(-l, -r, i));
	}	

	pq<pii> ativo;
	pq<pii> inativo;

	int x, y;
	fr(i, k){
		cin >> x >> y;
		inativo.push(mp(-x, -y));
	}

	ll soma = 0;
	frr(i, m){
		while(!inativo.empty()){
			if(inativo.top().first == -i){
				soma++;
				ativo.push(mp(inativo.top().second, inativo.top().first));
				inativo.pop();
			}
			else break;
		}

		d[i] = soma*d[i];

		while(!ativo.empty()){
			if(ativo.top().first == -i){
				soma--;
				ativo.pop();
			}
			else break;
		} 
	}

	soma = 0;

	frr(i, n){
		while(!inativo0.empty()){
			if(get<0>(inativo0.top()) == -i){
				soma += d[get<2>(inativo0.top())];
				ativo0.push(make_tuple(get<1>(inativo0.top()), get<0>(inativo0.top()), get<2>(inativo0.top())));
				inativo0.pop();
			}
			else break;
		}

		a[i] += soma;

		while(!ativo0.empty()){
			if(get<0>(ativo0.top()) == -i){
				soma -= d[get<2>(ativo0.top())];
				ativo0.pop();
			}
			else break;
		}
	}

	frr(i, n) cout << a[i] << " ";

	cout << endl;

	return 0;
}
