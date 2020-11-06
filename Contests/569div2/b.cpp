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
		int a[MAXN];
		int n;
		cin >> n;

		int mn = 0;
		fr(i, n){
				cin >> a[i];

				if(a[i] >= 0) a[i] = -a[i] - 1;

				if(a[i] < a[mn]) mn = i;
		}

		if(n%2 == 0){
				fr(i, n){
						cout << a[i] <<  " ";
				}
		}
		else{
				a[mn] = -a[mn] - 1;
				fr(i, n){
						cout << a[i] << " ";
				}
		}

}
