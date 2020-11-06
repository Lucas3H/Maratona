// https://codeforces.com/problemset/problem/961/D
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
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

ll crossProd(ponto a, ponto b, ponto c){
	ll x1 = a.f - b.f, x2 = c.f - b.f;
	ll y1 = a.s - b.s, y2 = c.s - b.s;

	return x1*y2 - x2*y1; 
}
ll n;
ponto p[MAXN];

set<int> marked;

void number_points_in_line(ponto a, ponto b){

	fr(i, n){
		if(crossProd(a, b, p[i]) == 0) marked.insert(i);
	}
}

void search_quadrilateral(){
	ll n_lin0 = 0, n_lin1 = 0, n_lin2 = 0;

	ll first = 0, second = 0;

	for(ll i = 2; i < n; i++){
		if(crossProd(p[0], p[1], p[i]) == 0) n_lin0++;
		else{
			first = i;
			break;
		}
	}

	if(first == 0){
		cout << "YES" << endl;
		return;
	}

	for(ll i = first + 1; i < n; i++){
		if(crossProd(p[0], p[1], p[i]) == 0) n_lin0++;
		else if(crossProd(p[0], p[first], p[i]) == 0) n_lin1++;
		else if(crossProd(p[1], p[first], p[i]) == 0) n_lin2++;
		else{
			second = i;
			break;
		}
	}

	if(second == 0){
		if(n_lin0 == 0 || n_lin1 == 0 || n_lin2 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else{
		number_points_in_line(p[0], p[1]);
		number_points_in_line(p[first], p[second]);
		if((int)marked.size() == n) {
			cout << "YES" << endl;
			return;
		}

		marked.clear();
		number_points_in_line(p[0], p[first]);
		number_points_in_line(p[1], p[second]);
		if((int)marked.size() == n) {
			cout << "YES" << endl;
			return;
		}

		marked.clear();
		number_points_in_line(p[0], p[second]);
		number_points_in_line(p[first], p[1]);
		if((int)marked.size() == n) {
			cout << "YES" << endl;
			return;
		}
		
		cout << "NO" << endl;
	}
}

int main(){
	cin >> n;

	fr(i, n){
		cin >> p[i].f >> p[i].s;
	}

	if(n <= 4){
		cout << "YES" << endl;
		return 0;
	}

	search_quadrilateral();
}
