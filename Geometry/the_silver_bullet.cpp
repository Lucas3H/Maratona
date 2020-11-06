// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2168 
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<double,double> pii;
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
#define eps 0.00000000001

int n;
vector<pii> gnu;

int max_alligned(int a){
	vector<pii> ang_coef;
	vector<int> number;

	fr(i, gnu.size()){
		if(i == a) continue;

		double dy = (gnu[i].s - gnu[a].s);
		double dx = (gnu[i].f - gnu[a].f);

		int achou = 0;
		fr(j, ang_coef.size()){
			if(abs((ang_coef[j].f)*dy - ang_coef[j].s*dx) < eps){
				achou = 1;
				number[j]++;
				break;
			}
		}

		if(!achou){
			ang_coef.pb(mp(dx, dy));
			number.pb(1);
		}
	}

	int ans = 0;
	for(auto x: number){
		ans = max(ans, x);
	}

	return ans + 1;
}

void insertion(pii a){
	fr(i, gnu.size()){
		if(abs(a.f - gnu[i].f) < eps && abs(a.s - gnu[i].s) < eps) return;
	}

	//cout << a.f << " " << a.s << endl;

	gnu.pb(a);
}

void read(){
	cin >> n;
	gnu.clear();

	fr(i, n){
		double x, y;
		cin >> x >> y;

		insertion(mp(x, y));
	}
}

int main(){
	int t;
	cin >> t;

	frr(ts, t){
		read();
		if(gnu.size() == 1) printf("Data set #%d contains a single gnu.\n", ts);
		else{
			int ans = 0;
			fr(i, gnu.size()){
				ans = max(ans, max_alligned(i));
			}

			printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n", ts, (int)gnu.size(), ans);
		}
	}
}
