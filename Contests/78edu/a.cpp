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
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		string p, h;
		cin >> p >> h;

		int tp = p.size(), th = h.size();
		int fr[30];
		int frp[30];
		fr(i, 26) frp[i] = 0;
		fr(i, tp) frp[p[i] - 'a']++;


		int deu = 0;

		for(int i = 0; i < th - tp + 1; i++){
			fr(j, 26) fr[j] = 0;

			for(int j = i; j < i + tp; j++) fr[h[j] - 'a']++;
			
			int passou = 1;
			fr(j, 26){
				if(fr[j] != frp[j]){
					passou = 0;
					break;
				}
			}

			if(passou){
				deu = 1;
				break;
			}
		}

		if(deu) cout << "YES\n";
		else cout << "NO\n";
	}
}
