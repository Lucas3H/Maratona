#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
		ios::sync_with_stdio(false);

		int n;
		cin >> n;

		string s;
		int v[10];
		mem(v, 0);

		cin >> s;

		fr(i, n){
				if(s[i] == 'L'){
						fr(i, 10){
								if(v[i] == 0){
										v[i] = 1;
										break;
								}
						}
				}
				else if(s[i] == 'R'){

							frm(i, 10){
									if(v[i] == 0){
											v[i] = 1;
											break;
									}
							}}
				else{
						v[s[i] - '0'] = 0;
				}
		}

		fr(i, 10) {
				cout << v[i];
			}
}
