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
#define MAXL 30
#define ROOT 1
#define INF 987654321

vector<vector<char>> ini, fim, meio;
vector<char> ans;

void build(string s){
	vector<char> inicio, final, meiuca;

	int first = -1, last = -1;

	int i = 0;
	while(i < s.size() && s[i] != '*'){
		inicio.pb(s[i++]);
	}
	first = i;

	i = s.size() - 1;
	while(i >= 0 && s[i] != '*'){
		final.pb(s[i--]);
	}
	last = i;


	for(i = first + 1; i < last; i++){
		if(s[i] != '*'){
			meiuca.pb(s[i]);
		}
	}

	//cout << first << " " << last << endl;

	if(inicio.size() > 0){
		ini.pb(inicio);
	}

	if(final.size() > 0){
		fim.pb(final);
	}

	if(meiuca.size() > 0){
		meio.pb(meiuca);
	}
}

int solveIni(){
	vector<char> pref;

	int deu = 1;

	fr(i, ini.size()){
		for(int j = 0; j < ini[i].size() && j < pref.size(); j++){
			if(ini[i][j] != pref[j])
				return 0;
		}

		for(int j = pref.size(); j < ini[i].size(); j++){
			pref.pb(ini[i][j]);
		}
	}

	fr(i, pref.size()){
		ans.pb(pref[i]);
	}

	return 1;
}

void solveMeio(){
	fr(i, meio.size()){
		fr(j, meio[i].size()){
			ans.pb(meio[i][j]);
		}
	}
}

int solveFim(){
	vector<char> suf;

	int deu = 1;

	fr(i, fim.size()){
		for(int j = 0; j < fim[i].size() && j < suf.size(); j++){
			if(fim[i][j] != suf[j])
				return 0;
		}

		for(int j = suf.size(); j < fim[i].size(); j++){
			suf.pb(fim[i][j]);
		}
	}

	frm(i, suf.size()){
		ans.pb(suf[i]);
	}

	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	frr(ts, t){
		int n;
		cin >> n;

		ini.clear();
		fim.clear();
		meio.clear();
		ans.clear();

		fr(i, n){
			string s;
			cin >> s;

			build(s);
		}

		cout << "Case #" << ts << ": ";

		if(solveIni() == 0){
			cout << "*\n";
			continue;
		}

		solveMeio();

		if(solveFim() == 0){
			cout << "*\n";
			continue;
		}

		fr(i, ans.size()){
			cout << ans[i];
		}

		cout << "\n";
	}
}
