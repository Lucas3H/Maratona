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
		int b, p, f, h, c;
		cin >> b >> p  >> f;
		cin >> h >> c;

		int ans = 0;
		if(h > c){
			if(b > 2*p){
				b -=2*p;
				ans+=h*p;

				if(b > 2*f){
					b-=2*f;
					ans+=c*f;
				}
				else{
					ans+=c*(floor(b/2));
				}
			}
			else{
				ans+=h*floor(b/2);
			}
		}
		else{
			if(b > 2*f){
				b -=2*f;
				ans+=c*f;

				if(b > 2*p){
					b-=2*p;
					ans+=h*p;
				}
				else{
					ans+=h*(floor(b/2));
				}
			}
			else{
				ans+=c*floor(b/2);
			}
		}

		cout << ans << endl;
	}
}
