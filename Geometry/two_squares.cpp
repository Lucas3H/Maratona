// https://codeforces.com/contest/993/problem/A
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

int main(){
	ios::sync_with_stdio(false);
	int x1[4], y1[4], x2[4], y2[4];
	fr(i, 4) cin >> x1[i] >> y1[i];
	fr(i, 4) cin >> x2[i] >> y2[i];

	int menor = 10000, maior = -10000;
	fr(i, 4){
		menor = min(menor, y2[i]);
		maior = max(maior, y2[i]);
	}

	int val = (maior - menor)/2;

	ponto centro;
	centro.f = ((x2[0] + x2[1] + x2[2] + x2[3])/4);
	centro.s = menor + val;

	int deu = 0;

	
	fr(i, 4){
		if(abs(centro.f - x1[i]) + abs(centro.s - y1[i]) <= val) deu = 1;
	}

	int l = 1000, r = -1000, up = -10000, down = 10000;
	fr(i, 4){
		l = min(l, x1[i]);
		r = max(r, x1[i]);

		down = min(down, y1[i]);
		up = max(up, y1[i]);
	}
	
	if(centro.f >= l && centro.f <= r && (abs(centro.s - up) <= val || abs(centro.s - down) <= val)) deu = 1;
	if(centro.s >= down && centro.s <= up && (abs(centro.f - l) <= val || abs(centro.f - r) <= val)) deu = 1;
	if(centro.f >= l && centro.f <= r && centro.s >= down && centro.s <= up) deu = 1;

	if(deu) cout << "YES" << endl;
	else cout << "NO" << endl;
}
