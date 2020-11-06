#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define ll long long

#define MAXN 100010

int main(){
	   ios::sync_with_stdio(false);

		int q;
		cin >> q;
		while(q--){
		 	ll n;
			cin >> n;
			ll m = n;

			int a = 0, b = 0, c = 0;
			while(n%5 == 0){
					 c++;
					 n/=5;
			}
			while(n%3 == 0){
					 b++;
					 n/=3;
			}
			while(n%2 == 0){
					 a++;
					 n/=2;
			}

			if(n > 1){
					 cout << -1 << endl;
					 continue;
			}
			//cout << a << " " << b << " " << c << endl;
			cout << (a + 2*c + b) + b + c << endl;
		}
}
