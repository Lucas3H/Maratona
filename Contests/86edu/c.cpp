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
     
ll q, a ,b, m;
     
int main(){
	ll t;
	cin >> t;
     
	while(t--){
        scanf("%lld %lld %lld", &a, &b, &q);
    	m = a*b;
     
        ll pref[40000];
        pref[0] = 0;

        ll tot = 0;

    	frr(i, m-1){
    		pref[i] = pref[i-1];
            if(((i%a)%b) != ((i%b)%a)){
                //cout << i << ' ';
                pref[i]++;
                tot++;
            }
        }
     
    	while(q--){
    		ll l, r;
            scanf("%lld %lld", &l, &r);
     
            ll ql = l/m, qr = r/m;

            if(l%m == 0){
                printf("%lld ", (qr - ql)*tot + pref[r%m]);
            }
            else{
                printf("%lld ", (qr - ql)*tot + pref[r%m] - pref[l%m - 1]);  
            }
    	}

        printf("\n");
    }
}