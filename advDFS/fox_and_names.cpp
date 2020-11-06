// https://codeforces.com/contest/512/problem/A
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
#define MAXL 30
#define ROOT 1

int n;
int deu = 1;
vector<int> adj[50];
int din[50];

int compare(string s, string t){
	int i = 0;

	while(i < s.size() && i < t.size()){
		if(s[i] == t[i]) i++;
		else{
			adj[s[i] - 'a'].pb(t[i] - 'a');
			din[t[i] - 'a']++;
			break;
		}
	}

	if(i == t.size()){
		return 0;
	}
	else return 1;
}

void read(){
	cin >> n;
	string s[110];

	fr(i, n){
		cin >> s[i];
		for(int j = 0; j < i; j++){
			if(compare(s[j], s[i]) == 0) deu = 0;
		}
	}
}

vector<int> ans;

int solve(){
	queue<int> fila;
	fr(i, 26){
		if(din[i] == 0) fila.push(i);
	}

	while(!fila.empty()){
		int u = fila.front();
		ans.pb(u);
		fila.pop();

		for(auto x: adj[u]){
			din[x]--;
			if(din[x] == 0) fila.push(x);
		}
	}

	//cout << ans.size() << endl;

	if(ans.size() == 26) return 1;
	else return 0;
}

int main(){
	read();

	//cout << deu << endl;

	if(deu == 0) cout << "Impossible\n";
	else{
		if(solve()){
			fr(i, ans.size()) cout << (char)(ans[i]+'a');
			cout << endl;
		}
		else cout << "Impossible\n";
	}
}
