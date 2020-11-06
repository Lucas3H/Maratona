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
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 1010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int cor[MAXN];
int ncors = 0;
int n;
int a[MAXN];

map<int, int> m;
int p[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve(){
	cin >> n;
	frr(i, n){
		cin >> a[i];
		fr(j, 11){
			if(a[i]%p[j] == 0){
				if(m[j+1] == 0){
					m[j+1] = ++ncors;
				}	
				cor[i] = j + 1;
				break;
			}
		}
	}

}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		m.clear();
		ncors = 0;
		solve();
		cout << ncors << endl;
		frr(i, n) cout << m[cor[i]] << ' ';
		cout << endl;
	}
}
