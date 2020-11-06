// https://codeforces.com/problemset/problem/135/B
// Nessa versão, os vértices devem estar na borda do quadrado/retangulo. Não necessariamente são vértices

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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

ponto p[8];
int dist(ponto a, ponto b){
	return (a.f - b.f)*(a.f - b.f) +  (a.s - b.s)*(a.s - b.s);
}

int crossProd(ponto a, ponto b, ponto c){
	int x1 = a.f - b.f, x2 = c.f - b.f;
	int y1 = a.s - b.s, y2 = c.s - b.s;

	return x1*y2 - y1*x2;
}

int dotProd(ponto a, ponto b, ponto c){
	int x1 = a.f - b.f, x2 = c.f - b.f;
	int y1 = a.s - b.s, y2 = c.s - b.s;

	return x1*x2 + y1*y2;
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

					int d = dist(p[j], p[k]);
					int dot1 = dotProd(p[i], p[j], p[k]);
					int cross1 = crossProd(p[j], p[k], p[l]);

					int cross2 = crossProd(p[i], p[j], p[k]);
					int dot2 = dotProd(p[j], p[k], p[l]);

					if(d == dot1 + cross1 && d == dot2 + cross2){
						deu[i] = 1;
						deu[j] = 1;
						deu[k] = 1;
						deu[l] = 1;
						achou =1 ;
						break;
					}
					
					if(d >= dot1 + cross1 && d > dot2 + cross2){
						deu[i] = 1;
						deu[j] = 1;
						deu[k] = 1;
						deu[l] = 1;
						achou =1 ;
						break;	
					}
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
