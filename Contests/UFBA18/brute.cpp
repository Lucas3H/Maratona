#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
    int lim = 100;

    for(int n = 2; n <= lim; n++){

	int x, y, cnt, mn, ans;

	ans = 0;
	frr(xx, n)
		frr(yy, n){
			x = xx;
			y = yy;

			if (x + y <= n){
				cnt = 0;

				while (cnt <= 100 and x > 0 and y > 0){
					mn = min(x, y);
			
					if (x < y){
						x += mn; y -= mn;
					}
					else{
						y += mn; x -= mn;
					}
					cnt++;
				}

				if (x == 0 or y == 0)
					ans += cnt;
			}
	}
	cout<<ans<<endl;
    }
}