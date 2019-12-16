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

ll a[3*MAXN], s[3*MAXN];
pair<ll, int> b[3*MAXN];

bool ord(pair<ll, int> a , pair<ll, int> b){
	if(a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main(){
		ios::sync_with_stdio(false);
		int n, k;
		cin >> n >> k;

		ll sum = 0;

		b[0] = mp(0, 0);
		frr(i, n) {
			cin >> a[i];
			sum+=a[i];
			b[i] = mp(sum, i);
			s[i] = sum;
		}

		sort(b , b + n + 1, ord);

		int ultimo = n, j = n+1;

		ll ans = 0;

		while(j >= k && k > 1){
				if(b[j].second < ultimo && b[j].second >= k-1){
					ans += (ll)k*(s[ultimo] - s[b[j].second]);
					k--;
					ultimo = b[j].second;
				//	cout << i << endl;
				}
				j--;
		}
		ans += k*(s[ultimo] - s[k-1]);

		frr(l, k-1) ans+=l*a[l];

		cout << ans << endl;
}
