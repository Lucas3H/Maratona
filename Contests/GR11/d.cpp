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
int p[100];
int n;
void change(vector<int> change){
	deque<int> aux;

	int tot = 0;
	for(int i = 0; i < change.size(); i++){
		for(int j = change[i] + tot; j > tot; j--){
			aux.push_front(p[j]);
		}

		tot+=change[i];
	}

	frr(i, n){
		p[i] = aux[i-1];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	frr(i, n) cin >> p[i];
/*
	frr(i, n){
		cout << p[i] << " ";
	}
	cout << endl;
*/
	vector<vector<int>> tot;
	fr(davez, n){
		vector<int> ans;
		int achou = 0;
		frr(i, n){
			if(p[i] == davez + 1) {
				achou = i;
				break;
			}
		}
		if((davez + n)%2 == 1){
			if(achou > 1) ans.pb(achou-1);
			ans.pb(n - davez - achou + 1);
			fr(i, davez) ans.pb(1);
		}
		else{
			fr(i, davez) ans.pb(1);
			ans.pb(achou - davez);
			if(achou < n)ans.pb(n - achou);
		}
		//cout << achou << " " << davez << endl;

		if(ans.size() > 1) tot.pb(ans);
		change(ans);

		/*
		cout << "----------\n";
		frr(i, n) cout << p[i] << " ";
		cout << endl;
		cout << "----------\n\n\n";	
		*/
	}
	cout << tot.size() << endl;
	for(auto x: tot){
		cout << x.size() << " ";
		for(auto y: x) cout << y << " ";
		cout << endl;
	}
}
