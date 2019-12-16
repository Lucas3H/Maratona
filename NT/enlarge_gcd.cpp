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

#define MAXN 4000
#define MOD 1000000007

int prime[MAXN];
vector<int> p;

map<int, int> m;

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

void dec(int n){
	int i = 0;
	int k = p.size();

	while(n > 1 && i < k){
		if(n%p[i] == 0){
			if(m.find(p[i]) == m.end()){
				m[p[i]] = 1;
			}
			else m[p[i]]++;

			while(n%p[i] == 0) n /= p[i];
		}

		i++;
	}

	if(n > 1){
		if(m.find(n) == m.end()) m[n] = 1;
		else m[n]++;
	}
}

int main(){
		ios::sync_with_stdio(false);

		for(int i = 2; i < MAXN; i++){
			if(prime[i] == 0){
				p.pb(i);
				for(int j = 2*i; j < MAXN; j+=i) prime[j] = 1;
			}
		}

		int n;
		cin >> n;

		int a[300010];
		fr(i, n){
			cin >> a[i];
		}

		int g = a[0];
		frr(i, n-1) g = gcd(g, a[i]);

		fr(i, n){
			a[i]/=g;
			dec(a[i]);
		}

		int maior = 0;
		for(auto& y: m){
			if(((y).second) > maior) maior = (y).second;
		}

		if(maior == 0) cout << -1 << endl;
		else cout << n - maior << endl;
}
