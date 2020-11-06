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
		int n;
		cin >> n;

		int b = 0, r = 0;
		int left[MAXN], right[MAXN];

		fr(i, n){
			cin >> left[n-i];
			if(left[n-i] == 1) b++;
			else r++;
		}

		frr(i, n){
			cin >> right[i];
			if(right[i] == 1) b++;
			else r++;
		}

/*

		saldo = 0;
		frr(i, n){
			if(left[i] == 1) saldo++
			else saldo--;

			saldoR[i] = saldo;
		}
*/
	//	cout << "Dif " << b - r << endl; 

		if(b == r) cout << 0 << endl;
		else if(b > r){
			int saldoR[MAXN], saldoL[MAXN];
			int saldo = 0;
			frr(i, n){
				if(right[i] == 1) saldo++;
				else saldo--;

				saldoR[i] = saldo;
			}

			saldo = 0;
			saldoL[0] = 0;
			frr(i, n){
				if(left[i] == 1) saldo++;
				else saldo--;

				saldoL[i] = saldo;
			}
/*
			frr(i, n) cout << saldoL[i] << " ";
			cout << endl;

			frr(i, n) cout << saldoR[i] << " ";
			cout << endl;
*/
			vector<int> v;
			v.pb(0);
			frr(i, n){
				v.pb(max(v[v.size() - 1], saldoR[i]));
			}

			int ans = 2*n;
			fr(i, n + 1){
				vector<int>::iterator aux = (lower_bound(v.begin(), v.end(), b - r - saldoL[i]));
				if(aux == v.end()) continue;
				int l = aux - v.begin();

				ans = min(ans, l + i);
				//cout << i <<  " " << ans << endl;

			}

			cout << ans << endl;
		}
		else{
			int saldoR[MAXN], saldoL[MAXN];
			int saldo = 0;
			frr(i, n){
				if(right[i] == 2) saldo++;
				else saldo--;

				saldoR[i] = saldo;
			}

			saldo = 0;
			saldoL[0] = 0;
			frr(i, n){
				if(left[i] == 2) saldo++;
				else saldo--;

				saldoL[i] = saldo;
			}

			vector<int> v;
			v.pb(0);
			frr(i, n){
				v.pb(max(v[v.size() - 1], saldoR[i]));
			}

			int ans = 2*n;
			fr(i, n + 1){
				vector<int>::iterator aux = (lower_bound(v.begin(), v.end(), r - b - saldoL[i]));
				if(aux == v.end()) continue;
				int l = aux - v.begin();

				ans = min(ans, l + i);
			}

			cout << ans << endl;
		}
	}
}
