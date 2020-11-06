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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	multiset<int> s;
	for(int i = 2; i <= n; i++){
		int p = 2, achou = 0;
		while(p*p <= i){
			if(i%p == 0){
				s.insert(i/p);
				achou = 1;
				break;
			}
			p++;
		}

		if(achou == 0) s.insert(1);
	}

	for(auto x: s) cout << x<< " ";
	cout << endl;
}
