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

bool comp(string s, string t){
	if(s.size() != t.size()) return 1;

	fr(i, s.size()){
		if(s[i] != t[t.size() - 1 - i]) return 1;
	}

	return 0;
}

int hashTable(vector<char> s){
	ll hash = 0;
	fr(i, s.size()){
		hash = (3*hash + s[i] - '0' + 1)%MOD;
	}

	return hash;
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<int> v[4];
		map<int, int> m;
		vector<char> a[2*MAXN];

		int h[2*MAXN];

		string s;

		frr(i, n){
			cin >> s;

			if(s[s.size() - 1] == '0'){
				if(s[0] == '0') v[0].pb(i);
				else v[1].pb(i);
			}
			else{
				if(s[0] == '1') v[3].pb(i);
				else{
					v[2].pb(i);
					//t2.push(s);
				}
			}

			vector<char> normal, inv;
			fr(j, s.size()){
				inv.pb(s[s.size() - 1 - j]);
				a[i].pb(s[j]);
			}

			h[i] = hashTable(a[i]);

			m[h[i]]++;
			m[hashTable(inv)]++;
		}
/*
		for(auto x: m){
			cout << x.f << " " << x.s << endl;
		}

		frr(i, n) {
			fr(j, a[i].size()) cout << a[i][j];
			cout << endl;
		}
*/
		if(v[1].size() == 0 && v[2].size() == 0){
			if(v[0].size() > 0 && v[3].size() > 0){
				cout << -1 << endl;
			}
			else{
				cout << 0 << endl << endl;
			}
		}
		else{
			if(v[2].size() > v[1].size()){
				int dif = (v[2].size() - v[1].size())/2;
				cout << dif << endl;
				int j = 0;

				while(dif){
					
					if(m[h[v[2][j]]] == 1){
						cout << v[2][j] << " ";
						dif--;
					}

					j++;
				}
			}
			else{
				int dif = (v[1].size() - v[2].size())/2;
				cout << dif << endl;
				int j = 0;

				while(dif){
					if(m[h[v[1][j]]] == 1){
						cout << v[1][j] << " ";
						dif--;
					}

					j++;
				}
			}
			

			cout << endl;
		}
	}
}
