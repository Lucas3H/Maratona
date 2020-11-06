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
	int n, k;
	cin >> n >> k;

	char aux;
	int a[2*MAXN], ans[2*MAXN];
	fr(i, n){
		cin >> aux;
		a[i] = aux - '0';
	}
	
	fr(i, n) ans[i] = a[(i%k)];

	int deu = 1;
	fr(i, n){
		if(ans[i] > a[i]){
			deu = 1;
			break;
		}
		else if(ans[i] < a[i]){
			deu = 0;
			break;
		}
	}

	if(deu){
		cout << n << endl;
		fr(i, n) cout << ans[i];
		return 0;
	}
	else{
		int achou = 0;
		frm(i, k){
			if(a[i] == 9) a[i] = 0;
			else{
				a[i] = a[i]+1;
				achou = 1;
				break;
			}
		}

		if(achou){
			fr(i, n) ans[i] = a[i%k];
			cout << n << endl;
			fr(i, n) cout << ans[i];
			return 0;
		}
		else{
			a[0] = 1;
			frr(i, k-1) a[i] = 0;
			fr(i, n + 1) ans[i] = a[i%k];
			cout << n + 1 << endl;
			fr(i, n + 1) cout << ans[i];
		}
	}
}
