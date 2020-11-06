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
string s;

int solvePos(int l, int r){
	int fr[26];
	fr(i, 26) fr[i] = 0;
	if(l < r){
		for(int i = l; i < n; i+=k){
			fr[s[i] - 'a']++;
		}

		for(int i = r; i < n; i+=k){
			fr[s[i] - 'a']++;
		}
	}
	else{
		for(int i = r; i < n; i+=k){
			fr[s[i] - 'a']++;
		}
	}

	int maximo = 0, soma = 0;
	fr(i, 26){
		maximo = max(maximo, fr[i]);
		soma+=fr[i];
	}

	return soma - maximo;
}

int solve(){
	int ans = 0;
	for(int i = 0; i < (k+1)/2; i++){
		ans+=solvePos(i, k - 1 - i);
	}
	return ans;
}



int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		cin >> n >> k;
		cin >> s;

		cout << solve() << endl;
	}
}
