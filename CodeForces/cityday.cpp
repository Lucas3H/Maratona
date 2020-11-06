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
		int n, x, y, a[MAXN];

		cin >> n >> x >> y;

		fr(i, n) cin >> a[i];

		for(int i = 0; i < n; i++){
			int deu = 1;
			for(int j = i - 1; j >= i - x && j >= 0; j--){
				if(a[j] < a[i]){
					deu = 0;
					break;
				}
			}

			for(int j = i + 1; j <= i + y && j < n; j++){
				if(a[j] < a[i]){
					deu = 0;
					break;
				}
			}

			if(deu == 0) continue;

			cout << i + 1 << endl;
			return 0;
		}
}
