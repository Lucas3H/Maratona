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

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

class NSE{
	public:
		int ans[MAXN], ans_inv[MAXN];

		void nse(int * v, int n){
			stack<int> aux;

			for(int i = 0; i < n; i++){
				while(aux.empty() == 0 && v[aux.top()] > v[i]){
					ans[aux.top()] = i;
					aux.pop();
				}

				aux.push(i);
			}
		}
			
		void nse_inv(int * v, int n){
			stack<int> aux;

			for(int i = n-1; i >= 0; i--){
				while(aux.empty() == 0 && v[aux.top()] > v[i]){
					ans_inv[aux.top()] = i;
					aux.pop();
				}

				aux.push(i);
			}
		}
};

int v[MAXN], dir[MAXN], pos[MAXN];

int main(){
	int n;
	cin >> n;

	NSE aux;
	fr(i, n){
		aux.ans[i] = -1;
		aux.ans_inv[i] = -1;
	}

	fr(i, n) {
		cin >> v[i];
		pos[v[i]] = i;
	}

	aux.nse(v, n);
	aux.nse_inv(v, n);

	if(v[0] == 1)
		dir[0] = 1;
	else 
		dir[0] = 0;

	frr(i, n-1){
		if(v[i] == 1){
			dir[i] = 1;
		}
		else{
			dir[i] = dir[i-1];
		}
	}
/*
	fr(i, n){
		cout << aux.ans_inv[i] << ' ';
	}
	cout << endl;

	frr(i, n){
		cout << dir[i] << " ";
	}
	cout << endl;
*/
	int ans = 0;
	cout << ans << ' ';
	for(int i = 2; i <= n; i++){
		//cout << pos[i] << " saodfkjaspodjopas " << endl;
		if(dir[pos[i]]){
			//cout << pos[i] << " asdasd " << aux.ans_inv[pos[i]] << endl;
			ans+=(pos[i] - aux.ans_inv[pos[i]] - 1);
			cout << ans<< ' '; 
		}
		else{
			//cout << aux.ans[pos[i]] << " " << pos[i] + 1 << " " << (i-1)
			ans+=(aux.ans[pos[i]] - pos[i] - 1 + (i-1));
			cout << ans << " ";
		}
	}
	cout << endl;

}
