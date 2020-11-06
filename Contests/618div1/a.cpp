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

set<int> bit[40];

void decompose(int n, int ind){
	int i = 0;
	while(n > 0){
		if(n%2 == 1){
			bit[i].insert(ind);
		}

		i++;
		n/=2;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	int x[MAXN];

	fr(i, n){
		cin >> x[i];
		decompose(x[i], i);
	}

	int fst = 0;
	frm(i, 40){
		if(bit[i].size() == 1){
			fst = (*bit[i].begin());

			break;
		}
	}

	cout << x[fst] << " ";
	fr(i, n){
		if(i == fst) continue;
		cout << x[i] << " ";
	}

	cout << endl;
}
