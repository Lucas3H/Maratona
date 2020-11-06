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

int n, m, k;
int ans = 0;

vector<pair<int, string>> v;

void four_right(int *tam){
	if((*tam) >= m - 1){
		v.pb(mp(m-1, "R"));

		ans++;

		(*tam) -= m - 1;
	}
	else{
		v.pb(mp((*tam), "R"));
		ans++;

		*tam = 0;
	}
}

void four_left(int *tam){
	if((*tam) >= m - 1){
		v.pb(mp(m-1, "L"));

		ans++;

		(*tam) -= m - 1;
	}
	else{
		v.pb(mp((*tam), "L"));

		ans++;

		*tam = 0;
	}
}


void four_up(int *tam){
	if((*tam) >= n - 1){
		v.pb(mp(n - 1, "U"));

		ans++;

		(*tam) -= n - 1;
	}
	else{
		v.pb(mp((*tam), "U"));

		ans++;

		*tam = 0;
	}
}

void four_down(int *tam){
	if((*tam) >= n - 1){
		v.pb(mp(n - 1, "D"));

		ans++;

		(*tam) -= n - 1;
	}
	else{
		v.pb(mp((*tam), "D"));

		ans++;

		*tam = 0;
	}
}

void cobrinha(int *tam){
	if((*tam) > 3*(m-1)){
		v.pb(mp(m-1, "DRU"));
		v.pb(mp(1, "D"));
		
		(*tam) -= 3*(m-1) + 1;

		ans+=2;
	}
	else{
		if((*tam >= 3)){
			v.pb(mp((*tam)/3, "DRU"));
			ans++;
		}

		if((*tam)%3 == 1) {
			v.pb(mp(1, "D"));
			ans++;
		}
		else if((*tam)%3 == 2) {
			v.pb(mp(1, "DR"));
			ans++;
		}

		(*tam) = 0;
	}
}

void print(){
	cout << ans << endl;
	fr(i, ans){
		cout << v[i].f << " " << v[i].s << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	if(k > 4*n*m - 2*n - 2*m){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";

	if(m == 1){
		four_down(&k);

		if(k == 0) {
			print();	
			return 0;
		}

		four_up(&k);

		print();

		return 0;
	}

	four_right(&k);
	if(k == 0) {
		print();
		return 0;
	}

	four_left(&k);
	if(k == 0) {
		print();
		return 0;
	}

	fr(i, n-1){
		cobrinha(&k);

		if(k == 0) break;

		four_left(&k);

		if(k == 0) break;
	}

	if(k == 0) {
		print();
		return 0;
	}

	four_up(&k);
	print();
}
