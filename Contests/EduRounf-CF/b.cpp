#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;

		set<pair<char, int>> a;
		int n = s.size();
		char c[110];
		fr(i, n ){
			c[i] = s[i];
		}

		sort(c, c+s.size());

		int ant = c[0], qtd = 0;
		fr(i, n){
			if(ant == c[i]) qtd++;
			else{
				ant = c[i];
				a.insert(mp(c[i-1], qtd));
				qtd = 1;
			}
		}

		if(a.size() <= 3) cout << "No answear" << endl;
		else{
			queue<pair<char, int>> resp;
			auto tam = a.begin();

			while(tam < a.end()){
				resp.push(*tam);
				tam += 2;
			}
			
			auto x = a.begin() +1;
			if(int((*x).first) == int((*tam).first) + 1 || int((*x).first) == int((*tam).first) - 1 ){
				if(tam == a.end()-1) tam = tam - 1;
				else tam = tam + 1;

				while(tam >= a.begin()){
					resp.push(a[tam]);
					tam-=2;
				}				
			}
			else{
				tam = a.begin() + 1;

				while(tam < a.end()){
					resp.push((*tam).first]);
					tam+=2;
				}
			}

			vector<char> v;
			fr(i, resp.size()){
				fr(j, resp.top().second) v.pb(resp.top().first);

				resp.pop();
			}

			fr(i, n) cout << v[i];

			cout << endl;
		}
	}
}
