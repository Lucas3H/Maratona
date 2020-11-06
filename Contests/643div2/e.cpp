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

int n, a, r, m;
vector<int> h;
int sumPref[MAXN];

ll getSum(ll l, ll r){
	return sumPref[r] - sumPref[l-1];
}

void read(){
	cin >> n >> a >> r >> m;
	ll sum = 0;
	frr(i, n) {
		ll x;
		cin >> x;
		h.pb(x);
		sum+=x;
		sumPref[i] = sum;
	}

	sort(h.begin(), h.end());
}

int solve(ll altura){
	int ind = h.lower_bound(altura) - h.begin();

	ll tira = getSum(ind + 1, n) - (n - ind + 1)*altura;
	ll coloca = altura*ind - getSum(1, ind);

	if(m <= a + r){
		if(tira)
	}
}

int main(){
	ios::sync_with_stdio(false);


}
