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

vector<pii> ans;
vector<char> s;
vector<int> pos;
int n, k;

int makeRegular(){
	int sum = 0;
	int ini = -1, end = -1;

	int ret = 0;

	fr(i, s.size()){
		if(s[i] == ')') sum--;
		else sum++;

		if(sum < 0 && ini == -1){
			ini = i;
		}
		if(sum == 0 && ini > -1){
			ans.pb(mp(ini, i));
			reverse(s.begin() + ini, s.begin() + i + 1);

			ini = -1;

		}

		if(sum == 0) {
			ret++;
			pos.pb(i);
		}
	}

	if(sum == 0) return ret;
	else return -1;
}

void buildMore(int l){
	int open = -1, close = -1;

	for(int i = 0; i < s.size() && l > 0; i++){
		if(s[i] == '(' && open == -1){
			open = i;
		}
		if(s[i] == ')' && open > -1){
			if(open < i - 1){
				ans.pb(mp(open + 1, i));
				reverse(s.begin() + open + 1, s.begin() + i + 1);
				l--;
				i = open + 1;
			}
			open = -1;
		}

	}
}

void print(){
	cout << ans.size() << "\n";
	for(auto x: ans){
		cout << x.f + 1 << " " << x.s + 1<< endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		ans.clear();
		pos.clear();
		s.clear();

		cin >> n >> k;
		fr(i, n){
			char c;
			cin >> c;
			s.pb(c);
		}

		int m = makeRegular();

		if(m > k){
			fr(i, m - k){
				ans.pb(mp(pos[i], pos[i] + 1));
			}
		}
		else if(m < k){
			buildMore(k - m);
		}

		print();
	}
}
