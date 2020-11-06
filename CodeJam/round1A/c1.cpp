// 
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100000
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll ans;
ll r, c;
		
bool isin(ll i, ll j){
	return (i >= 1 && i <= r && j >= 1 && j <= c);
}

int main(){
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	frr(ts, t){
		cin >> r >> c;

		ll m[r + 1][c + 1], not[r + 1][c + 1];

		vector<ll> row[110], col[110];

		ll sum = 0;

		frr(i, r){
			frr(j, c){
				cin >> m[i][j];
				sum += m[i][j];

				row[i].pb(j);
				col[j].pb(i);
			}
		}
	
		ans = sum;

		while(true){
			set<pii> tot;

			frr(i, r){
				queue<int> remove;

				fr(j, row[i].size()){
					ll av = 0, number = 0;

					if(isin(i - 1, row[i][j])){
						av += m[i-1][row[i][j]];
						number++;
					}
					if(isin(i + 1, row[i][j])){
						av += m[i+1][row[i][j]];
						number++;
					}
					if(j > 0 && isin(i, row[i][j-1])){
						av+=m[i][row[i][j-1]];
						number++;
					}
					if(j < row[i].size() - 1 && isin(i, row[i][j+1])){
						av+=m[i][row[i][j + 1]];
						number++;
					}

					if(number*m[i][row[i][j]] < av){
						tot.insert(mp(i, row[i][j]));
						remove.push(row[i][j]);
					}
				}


					int j = 0;
					while(j < row[i].size()){
						if(row[i][j] == remove.front()){
							tot.insert(mp(i, row[i][j]));
							row[i].erase(row[i].begin() + j, row[i].begin() + j + 1);
							remove.pop();
						}
						else j++;
					}
			}

			frr(i, c){

				queue<int> remove;

				fr(j, col[i].size()){
					ll av = 0, number = 0;

					if(isin(col[i][j], i-1)){
						av += m[col[i][j]][i-1];
						number++;
					}
					if(isin(col[i][j], i+1)){
						av += m[col[i][j]][i+1];
						number++;
					}
					if(j > 0 && isin(col[i][j-1], i)){
						av+=m[col[i][j-1]][i];
						number++;
					}
					if(j < col[i].size() - 1 && isin(col[i][j+1], i)){
						av+=m[col[i][j + 1]][i];
						number++;
					}

					if(number*m[col[i][j]][i] < av){
						tot.insert(mp(col[i][j], i));
						remove.push(col[i][j]);
					}
				}

					int j = 0;
					while(j < col[i].size()){
						if(col[i][j] == remove.front()){
							tot.insert(mp(col[i][j], i));
							col[i].erase(col[i].begin() + j, col[i].begin() + j + 1);
							remove.pop();
						}
						else j++;
					}
			}

			if(tot.size() == 0){
				break;
			}
			else{
				for(auto x: tot){
					sum-=m[x.f][x.s];
				}

				ans+=sum;
			}
		}

		cout << "Case #" << ts << ": ";
		cout << ans << "\n";
	}	
}
