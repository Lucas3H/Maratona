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

	char m[110][110];

	for(int i = 0; i < n; i++){
		if(i%2 == 0){

			for(int j = 0; j < n; j+=2){
				m[i][j] = 'B';
			}
		}
		else{

			for(int j = 1; j < n; j+=2){
				m[i][j] = 'B';
			}
		}
	}


		for(int i = 0; i < n; i++){
			if(i%2 == 1){

				for(int j = 0; j < n; j+=2){
					m[i][j] = 'W';
				}
			}
			else{

				for(int j = 1; j < n; j+=2){
					m[i][j] = 'W';
				}
			}
		}

	fr(i, n){
		fr(j, n) cout << m[i][j];

		cout << endl;
	}
}
