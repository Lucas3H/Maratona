// https://codeforces.com/problemset/problem/135/B
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
#define MAXL 30
#define ROOT 1

ponto p[8];
int dist(ponto a, ponto b){
	return (a.f - b.f)*(a.f - b.f) +  (a.s - b.s)*(a.s - b.s);
}

int dotProd(ponto a, ponto b, ponto c){
	int x1 = a.f - b.f, x2 = c.f - b.f;
	int y1 = a.s - b.s, y2 = c.s - b.s;

	return x1*x2 + y1*y2;
}

bool is_rectangle(ponto p[]){
	sort(p, p + 4);

	if(dotProd(p[0], p[1], p[3]) == 0 && dotProd(p[0], p[2], p[3]) == 0)
		return 1;
	else return 0;
}

int main(){
	ios::sync_with_stdio(false);

	fr(i, 8) cin >> p[i].f >> p[i].s;

	int deu[8];
	fr(i, 8) deu[i] = 0;

	int achou = 0;

	fr(i, 8){
		fr(j, 8){
			if(j == i) continue;
			fr(k, 8){
				if(k == j || k == i) continue;

				fr(l, 8){
					if(l == k || l == j || l == i) continue;

					int Continua = 0;

					int d1 = dist(p[j], p[i]);
					int d2 = dist(p[j], p[k]);
					int d3 = dist(p[k], p[l]);
					int d4 = dist(p[l], p[i]);

					int dot1 = dotProd(p[i], p[j], p[k]);
					
					if(d1 == d2 && d2 == d3 && d3 == d4 && dot1 == 0){
						deu[i] = 1;
						deu[j] = 1;
						deu[k] = 1;
						deu[l] = 1;

						Continua = 1;
					}

					if(Continua == 0) continue;

					vector<int> rec;

					fr(i, 8){
						if(deu[i] == 0) rec.pb(i);
					}

					ponto pt[4] = {p[rec[0]], p[rec[1]], p[rec[2]], p[rec[3]]};

					if(is_rectangle(pt)){
						achou = 1;
					}

					if(!achou){
						fr(i, 8) deu[i] = 0;
					}
					else break;
				}

				if(achou) break;
			}

			if(achou) break;
		}

		if(achou) break;
	}

	if(achou){
		cout << "YES" << endl;

		fr(i, 8){
			if(deu[i]) cout << i + 1 << " ";
		}
		cout << endl;
		
		fr(i, 8){
			if(!deu[i]) cout << i + 1 << " ";
		}
		cout << endl;
	}
	else cout << "NO" << endl;

}
