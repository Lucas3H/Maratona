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

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

int n, t, a, x, y, sum = 0;
int torn[50];
int nxt(int v){
	int aux = 0;

	fr(i, t){
		if((v & (1 << torn[i])) > 0){
			aux^=1;
		}
	}

	return v/2 + ((ll)1 << (n-1))*aux;
}

int first[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> t >> a >> x >> y;
	int a0 = a;
	fr(i, x) first[i] = -2;
	
	fr(i, t) cin >> torn[i];

	first[0] = -1;
	for(int i = 0; ; i++){
		sum = (sum + a)%x;
		if(first[sum%x] == -2){
			first[sum%x] = i;
		}
		else{
			if(i - first[sum%x] >= y){
				cout << first[sum%x] + 1 << " " << i << endl;
				return 0;
			}
		}

		a = nxt(a);
	}
}
