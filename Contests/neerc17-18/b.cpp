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

bool f(int a, int b, int c, int w, int h){
	if((a + b + c) <= w && (2*c + 2*a) <= h) return 1;
	if((2*a + b) <= w && (2*c + 2*a) <= h) return 1;
	if((2*a + c) <= w && (2*b + a + c) <= h) return 1;
	if((a + c) <= w && (3*b + a + c) <= h) return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	int a, b, c, w, h;
	cin >> a >>b >> c >> w >> h;

	if(f(a, b, c, w, h))
		cout << "Yes\n";
	else if(f(a, b, c, h, w))
		cout << "Yes\n";
	else if(f(a, c, b, w, h))
		cout << "Yes\n";
	else if(f(a, c, b, h, w))
		cout << "Yes\n";
	else if(f(b, a, c, w, h))
		cout << "Yes\n";
	else if(f(b, a, c, h, w))
		cout << "Yes\n";
	else if(f(b, c, a ,w, h))
		cout << "Yes\n";
	else if(f(b, c, a ,h, w))
		cout << "Yes\n";
	else if(f(c, a, b, w, h))
		cout << "Yes\n";
	else if(f(c, a, b, h, w))
		cout << "Yes\n";
	else if(f(c, b, a, w, h))
		cout << "Yes\n";
	else if(f(c, b, a, h, w))
		cout << "Yes\n";
	else 
		cout << "No\n";
}
