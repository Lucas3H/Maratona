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


int a[1010], b[1010];
int n;
vector<int> t[4];
vector<int> ans;

int solve(){
	if(t[0].size() + t[3].size() != 0 && t[0].size() + t[3].size() != n){
		cout << t[0].size() + t[3].size() << endl;
		fr(i, t[0].size()) cout << t[0][i] <<" ";
		fr(i, t[3].size()) cout << t[3][i] << " ";
		cout << endl;

		return 4;
	}
	else if(t[0].size() + t[3].size() == 0){
		if(t[1].size() != 0 && t[1].size() != n){
			cout << t[1].size() << endl;
			fr(i, t[1].size()) cout << t[1][i] <<" ";
			cout << endl;

			return 4;
		}
		else if(t[1].size() != 0) return 1;
		else return 2;
	}
	else{
		if(t[0].size() != 0 && t[0].size() != n){
			cout << t[0].size() << endl;
			fr(i, t[0].size()) cout << t[0][i] <<" ";
			cout << endl;

			return 4;
		}
		else if(t[0].size() != 0) return 0;
		else return 3;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>> n;

	frr(i, n){
		cin  >> a[i] >> b[i];

		a[i]+=1000000;
		b[i]+=1000000;

		if(a[i]%2 == 0 && b[i]%2 == 0) t[0].pb(i);
		else if(a[i]%2 == 0 && b[i]%2 == 1) t[1].pb(i);
		else if(a[i]%2 == 1 && b[i]%2 == 0) t[2].pb(i);
		else t[3].pb(i);
	}

	int ret = solve();

	while(ret!=4){

		t[ret].clear();
		frr(i, n){
			if(a[i]%2 == 0) a[i]/=2;
			else a[i] = (a[i]-1)/2;

			if(b[i]%2 == 0) b[i]/=2;
			else b[i] = (b[i] - 1)/2;
		}

		frr(i, n){
			if(a[i]%2 == 0 &&  b[i]%2 == 0) t[0].pb(i);
			else if(a[i]%2 == 0 && b[i]%2 == 1) t[1].pb(i);
			else if(a[i]%2 == 1 && b[i]%2 == 0) t[2].pb(i);
			else t[3].pb(i);
		}

		ret = solve();
	}

}
