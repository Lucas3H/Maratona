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

int n, k;
int m[2*MAXN];
int fr[2*MAXN], ac[2*MAXN];
int c[2*MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	fr(i, n){
		cin >> m[i];
		fr[m[i]]++;
		ac[m[i]]++;
	}

	frm(i, k){
		ac[i] += ac[i+1];
	}

	int ans = 0;

	cout << endl;

	frr(i, k) {
		cin >> c[i];
		//cout << (int)ceil(ac[i]/c[i]) << " " << ac[i] << " " << c[i] << endl;
		ans = max(ans, (int)ceil((double)ac[i]/c[i]));
	}
	cout << endl;

	vector<int> v[2*MAXN];

	int ind = 0;

	frm(i, k+1){
		fr(j, fr[i]){
			v[ind%ans].pb(i);
			ind++;
		}
	}

	cout << ans << endl;

	fr(i, ans){
		cout << v[i].size() << " ";
		for(auto x: v[i]) cout << x << " ";
		cout << endl;
	}
}
