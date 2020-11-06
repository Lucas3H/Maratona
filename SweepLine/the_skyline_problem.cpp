// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=41
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

#define MAXN 10011
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

vector<pii> x[MAXN];
int y[MAXN];
int ans[MAXN];

int main(){
	int k = 0;

	int maior = 0;

	int xl, xr, Y;

	while(cin >> xl >> Y >> xr){
		x[xl].pb(mp(Y, 0));
		x[xr].pb(mp(Y, 1));

		maior = max(maior, xr);

		k++;
	}

	fr(i, maior + 1){
		if(x[i].size() == 0) {
			frm(j, MAXN){
				if(y[j]){
					ans[i] = j;
					break;
				}
			}
			continue;
		}
		for(auto a: x[i]){
			if(a.s) y[a.f]--;
			else y[a.f]++;
		}

		frm(j, MAXN){
			if(y[j]){
				ans[i] = j;
				break;
			}
		}
	}

	int i = 0;
	vector<int> pr;

	while(i < maior){
		while(i < maior && ans[i] == ans[i+1]) i++;
		

		pr.pb(i+1);
		pr.pb(ans[i+1]);
		i++;
	}

	fr(j, pr.size() - 1) cout << pr[j] << " ";
	cout << pr[pr.size() - 1];
	

	cout << endl;
}
