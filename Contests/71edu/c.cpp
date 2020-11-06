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
#define MAXL 30
#define ROOT 1

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		ll n, a, b;
		cin >> n >> a >> b;
		string aux;
		cin >> aux;
		ll s[2*MAXN];
		fr(i, n) s[i] = aux[i] - '0';

		int size = 0, blocos = 0;
		vector<ll> zeros, uns;
		fr(i, n-1){
			if(s[i] == 0) {
				size++; 
				if(s[i+1] == 1){
					zeros.pb(size);
					size = 0;
				}
			}
			else{
				size++;
				if(s[i+1] == 0){
					uns.pb(size);
					size = 0;
				}
			}
		}

		size++;
		zeros.pb(size);
		
		int alto = 1;
		ll ans = n*a + (n+1)*b;
		fr(i, uns.size()){
			if(alto == 2){
				ans+=min(2*a ,(zeros[i] - 1)*b);
			}
			else{
				ans+=a;
			}
			alto = 2;

			ans+=b*(uns[i]+1);
		}

		if(alto == 2)ans+=a;

		cout << ans << endl;

	}
}
