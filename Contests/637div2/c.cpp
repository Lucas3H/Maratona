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

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		int n;
		int p[MAXN], pos[MAXN];
		cin >> n;
		frr(i, n) {
			cin >> p[i];
			pos[p[i]] = i;
		}

		int last = n + 1, ind = 1;
		int deu = 1;
		while(last != 1){
			int aux = last;
			last = pos[ind];
			for(int i = pos[ind]; i < aux; i++){
				if(pos[ind] != i){
					deu = 0;
					break;
				}
				ind++;
			}

			if(deu == 0)
				break;
		}

		if(deu) cout << "Yes\n";
		else cout << "No\n";
	}
}
