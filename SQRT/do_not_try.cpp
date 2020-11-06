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
#define ROOT 1
#define INF 987654321


const int sq = (int)sqrt(MAXN);

string s;
int prior[MAXN];
int q;

/*
	((prioridade, -fim), car)
*/

pq<pair<pii, int>> resto[sq][sq];

/*
	((-inicio, prioridade), (car, fim))
*/
pq<pair<pii, pii>> to_enter[sq][sq];


void solveHeavy(int l, int r, int jmp, char c, int p){
	for(int i = l; i <= r; i+=jmp){
		if(p > prior[i]){
			prior[i] = p;
			s[i] = c;
		}
	}
}

void solvePos(int m, int q, int r){
	while(resto[m][r].empty() == 0 && -resto[m][r].top().f.s < m*q + r){
		resto[m][r].pop();
	}

	if(resto[m][r].empty() == 0){
		if(prior[m*q + r] < resto[m][r].top().f.f){
			prior[m*q + r] = resto[m][r].top().f.f;
			s[m*q + r] = (char)resto[m][r].top().s;
		}
	}
}

void solveresto(int m, int r){
	int davez = r, q = 0;

	/*
	if(to_enter[m][r].empty() == 0){
		cout << to_enter[m][r].top().f.f << " " << m << " " << r << endl;
	}
	*/
	while(davez < s.size()){
		while(to_enter[m][r].empty() == 0 && to_enter[m][r].top().f.f == -davez){
			resto[m][r].push(mp(mp(to_enter[m][r].top().f.s, -to_enter[m][r].top().s.s), to_enter[m][r].top().s.f));
			to_enter[m][r].pop();
		}

		solvePos(m, q, r);
		q++;
		davez+=m;
	}
}

void solveLight(int m){
	fr(i, m){
		solveresto(m, i);
	}
}

void read(){
	cin >> s;
	cin >> q;

	int i, a, k;
	char c;
		
	frr(j, q){
		cin >> i >> a >> k >> c;
	
		if(a >= sq){
			solveHeavy(i-1, i-1 + a*k, a, c, j);
		}
		else{
			to_enter[a][(i-1)%a].push(mp(mp(-i+1, j), mp((int)c, i-1 + a*k)));
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	read();
	frr(i, sq-1){
		solveLight(i);
	}

	cout << s << endl;

}
