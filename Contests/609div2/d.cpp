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
	ll n;
	cin >> n;

	ll a[3*MAXN];
	ll black = 0, white = 0;

	frr(i, n){
		cin >> a[i];
		if(a[i]%2 == 0){
			black += a[i]/2;
			white += a[i]/2;
		}
		else{
			if(i%2 == 0){
				black += a[i]/2;
				white += (a[i]+1)/2;	
			}
			else{
				black += (a[i]+1)/2;
				white += a[i]/2;			
			}
		}
	}

	cout << min(black, white) << endl;
}
