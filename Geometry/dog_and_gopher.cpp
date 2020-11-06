// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1251 
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
#define eps 0.000001

int n;
ponto dog, golpher;
ponto p[1010];

double dist(ponto a, ponto b){
	return (a.f - b.f)*(a.f - b.f) + (a.s - b.s)*(a.s - b.s);
}

void solve(){
	fr(i, n){
		//cout << dist(dog, p[i]) << " " << dist(golpher, p[i]);
		if(dist(dog, p[i]) - 4*(dist(golpher, p[i])) > -eps){
			printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", p[i].f, p[i].s); 
			return;
		}
	}

	printf("The gopher cannot escape.\n");
}

int read(){
	if(!(cin >> n)) return 0;

	cin >> golpher.f >> golpher.s >> dog.f >> dog.s;

	fr(i, n){
		cin >> p[i].f >> p[i].s;
	}

	return 1;
}

int main(){
	while(read()){
		solve();
	}
}
