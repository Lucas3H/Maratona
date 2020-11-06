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
#define INF 1000000000000000100

deque<deque<int>> solve(int n){
	//cout << ini.size() << " " << fim.size() << endl;	
	deque<deque<int>> ret;
	if(n == 1){
		deque<int> d;
		d.pb(1);

		ret.pb(d);

		return ret;
	}
	else if(n == 2){
		deque<int> d1, d2;
		d1.pb(1);
		d1.pb(2);
		d2.pb(2);
		d2.pb(1);

		ret.pb(d1);
		ret.pb(d2);

		return ret;
	}

	deque<deque<int>> aux = solve(n-1);

	for(int i = 0; i < aux.size(); i++){
		deque<int> davez = aux[i];
		if(i%2 == 0){
			davez.pb(n);
			ret.pb(davez);
			for(int j = n-1; j > 0; j--){
				swap(davez[j], davez[j-1]);
				ret.pb(davez);
			} 
		}
		else{
			davez.push_front(n);
			ret.pb(davez);
			for(int j = 0; j < n-1; j++){
				swap(davez[j], davez[j+1]);
				ret.pb(davez);
			} 
		}
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	deque<deque<int>> d;

	d = solve(n);

	for(auto x: d){
		for(auto y: x){
			cout << y << " ";
		}
		cout << endl;
	}
}
