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

int main(){
	ios::sync_with_stdio(false);

	string s;
	int n, k;

	int nr = 0, nl = 0;

	cin >> n >> k >> s;

	vector<int> posl;


	fr(i, s.size()){
		if(s[i] == 'L') {
			nl++;
			posl.pb(i);
		}
		else{
			nr++;
		}
	}

	if(posl.size() == 0 || posl[posl.size() - 1] == posl.size() - 1){
		cout << -1 << endl;
		return 0;
	}

	vector<queue<int>> ans;
	int ind = 0, sum = 0;
	while(posl[posl.size() - 1] > posl.size() - 1){
		queue<int> aux;
		frm(i, posl.size()){
			if(posl[i] > 0 && s[posl[i]-1] == 'R'){
				swap(s[posl[i]-1], s[posl[i]]);
				aux.push(posl[i]);
				posl[i]--;

				sum++;
			}
		}

		ans.pb(aux);

		ind++;
	}


	if(sum >= k && ind <= k){
		int j = 0, fix = ind;
		while(ind < k){
			cout << 1 << " " << ans[j].front() << "\n";
			ans[j].pop();
			k--;
			
			if(ans[j].size() == 0) {
				j++;
				ind--;
			}
		}

		for(int i = j; i < fix; i++){
			int sz = ans[i].size();
			cout << sz <<" ";
			fr(l, sz){
				cout << ans[i].front() << " ";
				ans[i].pop();
			}
			cout << "\n";

		}
	}
	else{
		cout << -1 << endl;
	}
}
