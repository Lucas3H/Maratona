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

const double pi = acos(-1);

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
double r;
double dist[110][110];
int a, b, c, d;
	
bool is_valid(int x, int y){
	if(x >= 0 && x <= m && y >= 0 && y <= n)
		return true;
	else 
		return false;
}

void bfs(){
	int pr[110][110];
	mem(pr, 0);

	fr(i, m+1){
		fr(j, n+1) dist[i][j] = 1000000.0;
	}

	pq<pair<double, pii>> fila;
	fila.push(mp(0, mp(a, b)));

	while(!fila.empty()){
		pair<double, pii> davez = fila.top();
		fila.pop();

		if(pr[davez.s.f][davez.s.s]) continue;

		pr[davez.s.f][davez.s.s] = 1;
		dist[davez.s.f][davez.s.s] = min(-davez.f, dist[davez.s.f][davez.s.s]);

		//printf("%d %d\n", davez.s.f, davez.s.s);

		fr(i, 4){
			int X = davez.s.f + dx[i];
			int Y = davez.s.s + dy[i];
			
			if(is_valid(X, Y) && pr[X][Y] == 0){
				if(X == davez.s.f){
					fila.push(mp(davez.f - r/n, mp(X, Y)));
				}
				else{
					fila.push(mp(davez.f - r*((double)Y/n)*pi/m, mp(X, Y)));
				}
			}
		}
	}
}

void read(){
	cin >> m >> n >> r;
	cin >> a >> b >> c >> d;

	bfs();
/*
	fr(i, m+1){
		fr(j, n+1){
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
*/
	printf("%.8lf\n", dist[c][d]);
}

int main(){
	read();
}
