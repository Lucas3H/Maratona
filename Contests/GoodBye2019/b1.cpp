    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define fr(i, n) for(ll i = 0; i < n; i++)
    #define frr(i, n) for(ll i = 1; i <= n; i++)
    #define frm(i, n) for(ll i = n-1; i >= 0; i--)
     
    #define pb push_back
    #define f first
    #define s second
     
    typedef long long ll;
    typedef pair<ll,ll> pii;
    typedef pair<ll, ll> ponto;
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
    	ll t;
    	cin >> t;
     
     
    	while(t--){
    		ll n;
    		cin >> n;
     
    		ll a[2*MAXN];
    		ll maior = 1, menor = 1;
			int deu = 0;
    		frr(i, n) {
    			cin >> a[i];
			}

			int ans = 0;
			frr(i, n - 1){
				if(a[i] - a[i+1] >= 2 || a[i] - a[i+1] <= -2){
					ans = i;
					break;
				}
			}

			if(ans != 0){
				cout << "YES" << endl;
				cout << ans <<" " << ans+1 << endl;
			}
			else{
				cout << "NO" << endl;
			}
    	}
    }