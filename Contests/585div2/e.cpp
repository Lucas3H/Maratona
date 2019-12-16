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

vector<int> v[21];
vector<int> s[21];

int n;
int a[MAXN];

int bb(int l, int r, int cor){
	if(v[cor].size() == 0) return 0;

	int ini = l, fim = r, meio = (l+r)/2;

	if(v[cor][r - l] - r < 0) return r - l + 1;
	if(v[cor][0] - l > 0) return 0;

	while(ini < fim){

		meio = (ini+fim)/2;

		if(v[cor][meio - l] - meio < 0 && v[cor][meio+1 - l] - (meio + 1) >= 0) return meio+1 - l;
		else if(v[cor][meio - l] - (meio) < 0) ini = meio;
		else fim = meio;

//		cout << meio << " " << ini << " " << fim << " " << cor << endl;
//		cout << v[cor][meio - l] - meio << " " << v[cor][meio- l  + 1] << endl;
	}

	return meio - l;
}

int mov(int pos, int cor){

	int ind = bb(pos, pos + v[cor].size() - 1, cor);

	int t = v[cor].size();
/*
	cout << ind << ' ' << cor << " " << pos <<" " << t<< endl;
	cout << s[cor][pos] << " ";

	if(t < ind){
		cout << cor << " " << pos << endl;
		cout << t << " " << ind << endl;
	}
*/

	int ans = (ind*pos + ind*(ind-1)/2 - s[cor][ind]) + s[cor][t] - s[cor][ind];
	ans -= (t - ind)*pos + (t-1)*t/2 - (ind-1)*ind/2;
/*
	if(cor == 2 && pos == 12){
		cout << "II " << ind << " " << t << " " << s[cor][t] << " " << endl;
	}*/

	return ans;
}

int dp[1123456];

int bit(int mask){
	int m = mask;
	int t = 0;
	vector<int> b;

	int i = 0;
	while(m > 0){
		if(m%2 == 1){
			t += v[i].size();
			b.pb(i);
		}

		i++;
		m/=2;
	}

	ll ans = 112345678901234567;
	fr(i, b.size()){
		if(mask == 16){
			cout << "b " << b[i] << " mask " << (mask&~(1 << (b[i]))) << " dp " << (ll)dp[mask&~(1 << (b[i]) )] <<" t - v " << t-v[b[i]].size() << " m " << (ll)mov(t - v[b[i]].size(), b[i]) << endl;
		}
		ans = min(ans, (ll)dp[mask&~(1 << (b[i]) )] + (ll)mov(t - v[b[i]].size(), b[i]));
	}


	if(mask < 128 && mask >= 4) cout << mask << " " << ans << endl;
	return dp[mask] = ans;
}

int main(){
	ios::sync_with_stdio(false);

	fr(i, 20) s[i].pb(0);

	cin >> n;
	fr(i, n){
		cin >> a[i];
		v[a[i]-1].pb(i);

		s[a[i]-1].pb(s[a[i]-1][ s[a[i]-1].size() - 1 ] + i );
	}

	frr(i, (1 << 20) - 1){
		bit(i);
	}

	cout << dp[(1 << 20) - 1] << endl;
}
