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

string s;
int k;

int ativo[MAXN];
vector<int> pos_letra[30];

void solve_letter(int l, int pos){
	int best = pos;
	fr(i, pos){
		if(ativo[i] != -1 && ativo[i] < l){
			best = i;
		}
	}

	k -= (l - ativo[best] - 1);
	ativo[best] = -1;
	ativo[pos] = l;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> k;
	cin >> s;

	fr(i, s.size()) {
		a[i] = (-1);
		pos_letra[s[i] - 'a'].pb(i);
	}

	fr(i, 26){
		for(auto x: pos_letra[i]){
			solve_letter(i, x);
		}
	}

	if(k < 0){
		cout << "IMPOSSIBLE\n";
	}
	else{
		int ans = 0 ;
		fr(i, s.size()){
			if(ativo[i] != -1) ans++;
		}

		cout << ans << endl;
	}
}
