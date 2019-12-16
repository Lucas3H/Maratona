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
	 	ll n, I;
		cin >> n >> I;

		I*=8;
		int k = I/n;

		vector<int> a;

		int x;
		fr(i, n){
			cin >> x;
			a.pb(x);
		}

		sort(a.begin(), a.end());

		vector<pii> b;

		b.pb(mp(a[0], 1));
		int  j = 0;

		frr(i, n-1){
			if(a[i] == b[j].first){
				b[j].second++;
			}
			else{
				b.pb(mp(a[i], 1));
				j++;
			}
		}

	//	cout << log(b.size()) << " " << 2*log(k) << endl;

		int maior = 0;
		int sum = 0;

		if(k*log(2)-log(b.size()) >= 0.00000000){
			cout << 0 << endl;
			return 0;
		}

		int i = 0;
		while(i < (1 << k)){
			sum += b[i].second;
			i++;
			//cout << sum << endl;
		}

		while(i < b.size()){
			if(sum > maior) maior = sum;

			sum+=b[i].second;
			sum-=b[(i-(1 << k))].second;
			i++;
		}

		cout << n - maior << endl;
}
