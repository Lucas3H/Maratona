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

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		scanf("%d", &n);

		set<int> v[4];
		map<string, int> m;
		int tam[4] = {0, 0, 0, 0};
		string s;

		frr(i, n){
			cin >> s;

			string l = s;
			reverse(l.begin(), l.end());

			int group;
			if(s[s.size() - 1] == '0'){
				if(s[0] == '0') {
					group = 0;
					tam[0]++;
				}
				else {
					group = 1;
					tam[1]++;
				}
			}
			else{
				if(s[0] == '1'){
					group = 3;
					tam[3]++;
				}
				else {
					group = 2;
					tam[2]++;
				}
			}

			if(m[l]) {
				v[3 - group].erase(m[l]);
				m[l] = 0;
			}
			else{
				v[group].insert(i);
				m[s] = i;
			}
		}
/*
		for(auto x: m) cout << x.f << " " << x.s << endl;
		cout << "tam\n";
		fr(i, 4) cout << tam[i] << ' ';
		cout << endl; 
*/
		if(tam[1] == 0 && tam[2] == 0){
			if(tam[0] > 0 && tam[3] > 0){
				printf("-1\n");
			}
			else{
				printf("0\n\n");
			}
		}
		else{
		/*	db;
			cout << tam[2] << " " << tam[1] << endl;
		*/	if(tam[2] > tam[1]){
				int dif = (tam[2] - tam[1])/2;
				printf("%d\n", dif);
				int j = 0;

				for(auto x: v[2]){
					if(dif == 0) break;
					cout << x << " ";
					dif--;
				}
			}
			else{	
				int dif = (tam[1] - tam[2])/2;
				printf("%d\n", dif);
				int j = 0;

				for(auto x: v[1]){
					if(dif == 0) break;
					cout << x << " ";
					dif--;
				}
			}
			

			printf("\n");
		}
	}
}
