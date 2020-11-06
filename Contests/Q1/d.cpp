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
#define INF 987654321

pq<pair<pii, pii>> fila[26];

int ord[MAXN];
string s;

void solve(int ind){
	cout << ind << endl;
	while(fila[ind].empty() == 0){
		pair<pii, pii> davez = fila[ind].top();
		fila[ind].pop();

		int position = -davez.f.f;
		davez.s.f--;

		cout << position << " ";

		if(ord[position] < davez.s.s){
			ord[position] = davez.s.s;
			s[position] = ind + 'a';
		}

		if(davez.s.f > 0){
			davez.f.f-=davez.f.s;
			fila[ind].push(davez);
		}
	}

	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> s;

	int q;
	cin >> q;
	frr(j, q){
		int i, a, k;
		char c;
		cin >> i >> a >> k >> c;

		i--;

		fila[c - 'a'].push(mp(mp(-i, a), mp(k + 1, j)));
	}

	fr(i, 26){
		solve(i);
	}

	cout << s << endl;
}
