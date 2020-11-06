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
typedef pair<ll, ll> pll;
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
#define INF 1000000000000000100

vector<pii> build(string s){
	vector<pii> ret;
	int i = 0;
	while(i < s.size()){
		char davez = s[i];
		int tam = 0, ini = i;
		while(i < s.size() && davez == s[i]){
			tam++, i++;
		}

		ret.pb({tam, ini});
	}

	return ret;
}

int count(string s){
	s = 'L' + s;
	int ans = 0;
	for(int i = 1; i < s.size(); i++){
		if(s[i] == 'W'){
			if(s[i-1] == 'W') ans+=2;
			else ans++;
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		int n, k, ini = 0;
		string s;
		cin >> n >> k >> s;

		vector<pii> b = build(s);
		vector<pii> aux;
		if(s[0] == 'L') ini = 2;
		else ini = 1;

		for(int i = ini; i < b.size() - 1; i += 2){
			aux.pb(b[i]);
			//cout << b[i].s << " ";
		}
		//cout << endl;

		sort(aux.begin(), aux.end());

		for(auto x: aux){
			int ini = x.s, tam = x.f;

			if(k < tam){
				for(int i = ini; i < ini + k; i++){
					s[i] = 'W';
				}
				k = 0;
				break;
			}
			else{
				for(int i = ini; i < ini + tam; i++) s[i] = 'W';
				k -= tam;
			}
		}

		if(k > 0){
			if(s[0] == 'L'){
				for(int i = b[0].f - 1; k > 0 && i >= 0; i--){
					s[i] = 'W';
					k--;
				}
			}

			if(s[n-1] == 'L'){
				for(int i = b[b.size() - 1].s; k > 0 && i < n; i++){
					s[i] = 'W';
					k--;
				}
			}
		}

		//cout << s << endl;

		cout << count(s) << endl;
	}
}
