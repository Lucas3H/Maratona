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

	int n;
	cin >> n;

	int a[2*MAXN], ans[2*MAXN];
	frr(i, n) cin >> a[i];
	frr(i, n) a[i + n] = a[i];

	vector<int> nao_eliminado;
	int maior = a[1];
	nao_eliminado.pb(1);

	for(int i = 2; i <= 3*n; i++){
		if(2*a[i] < maior){
			fr(j, nao_eliminado.size()) ans[nao_eliminado[j]] = i - nao_eliminado[j];

			nao_eliminado.clear();
			maior = a[i];
			nao_eliminado.pb(i);
		}
		else{
			nao_eliminado.pb(i);
			maior = max(maior, a[i]);
		}
	}


	frr(i, n) cout << ans[i] << " ";
	cout << endl;
}
