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
typedef pair<ll, ll> pll;
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

int n;
int a[MAXN];

int get_height(int p, int h){
	if( p <= h) return p;
	else return (h - (p - h));
}

int get_point(int h){
	return h;
}

bool da_certo(int h){
	int p = 1;
	for(int i = 1; i <= n; i++){
		if(p >= 2*h) break;

		if(get_height(p, h) <= a[i]){
			p++;
		}
		else{
			p = a[i] + 1;
		}
	}

	if(p >= 2*h) return true;
	else return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;

	frr(i, n) cin >> a[i];

	int l = 0, r = n + 1, m;
	while(l < r - 1){
		m = (l + r)/2;
	
		if(da_certo(m)){
			l = m;
		}
		else{
			r = m;
		}
	}

	cout << l << endl;
}
