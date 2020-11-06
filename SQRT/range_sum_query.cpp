// https://codeforces.com/group/BDIXyZZHhT/contest/205512/problem/D
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

ll n, len, q;
vector<ll> a(MAXN);
vector<ll> b(MAXN);

void build(){
	scanf("%lld %lld", &n, &q);
	len = (int)sqrt(n + .0) + 1;

	fr(i, n) scanf("%lld", &a[i]);
	fr(i, n){
		b[i/len] += a[i];
	}
}

void update(int i, ll val){
	b[i/len]+=val-a[i];
	a[i] = val;
}

ll query(int l, int r){
	ll sum = 0;

	for(int i = l; i <= r;){
		if(i%len == 0 && i + len - 1 <= r){
			sum+=b[i/len];
			i+=len;
		}
		else{
			sum+=a[i];
			i++;
		}
	}

	return sum;
}

int main(){
	build();
	//cout << len << endl;

	fr(i, q){
		int l, r;
		char c;
		scanf(" %c %d %d", &c, &l, &r);

		if(c == '?') printf("%lld\n", query(l - 1, r - 1));
		else update(l - 1, r);
	}

}
