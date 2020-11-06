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
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if(b < a-1 || c < d-1){
		cout << "NO" << endl;
		return 0;
	}
	if(b == a-1){
		if(c + d == 0){
			cout << "YES" << endl;
			int j = 0;
			fr(i, a + b){
				cout << j << " ";
				j = 1 - j;
			}
		}
		else cout << "NO" << endl;
		return 0;
	}
	if(c == d-1){
		if(a + b == 0){
			cout << "YES" << endl;
			int j = 0;
			fr(i, c + d){
				cout << 3 - j << " ";
				j = 1 - j;
			}
		}
		else cout << "NO" << endl;
		return 0;
	}

	if(a + c == b + d){
		cout << "YES" << endl;
		int j = 0;
		fr(i, a + a){
			cout << j << " ";
			j = 1 - j;
		}
		j = 1;
		fr(i, d + d){
			cout << 3 - j << " ";
			j = 1 - j;
		}
		j = 0;
		fr(i, c - d + c - d){
			cout << 2 - j <<" ";
			j = 1 - j;	
		}
	
		return 0;
	}

	if(a + c == b + d + 1){
		cout << "YES" << endl;
		int j = 0;
		fr(i, a + a){
			cout << j << " ";
			j = 1 - j;
		}
		j = 1;
		fr(i, d + d){
			cout << 3 - j << " ";
			j = 1 - j;
		}
		j = 0;
		fr(i, b - a + b - a){
			cout << 2 - j << " ";
			j = 1 - j;	
		}
		cout << 2 << " ";

		return 0;
	}

	if(a + c + 1 == b + d){
		cout << "YES" << endl;
		int j = 0;
		fr(i, d + d){
			cout << 3 - j << " ";
			j = 1 - j;
		}
		j = 1;
		fr(i, a + a){
			cout << j << " ";
			j = 1 - j;
		}
		
		j = 0;
		fr(i, c - d + c - d){
			cout << 1 +  j << " ";
			j = 1 - j;	
		}
		cout << 1 << " ";
		return 0;
	}

	cout << "NO" << endl;
}
