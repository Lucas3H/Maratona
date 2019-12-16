#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	if(k == 0){
		cout << s << endl;
		return 0;
	}

	if(s.size() == 1){
		cout << 0 << endl;
		return 0;
	}
	int l = s.size();

	if(s[0] != '1'){
		s[0] = '1';
		k--;
	}

	int i = 1;
	while(i < l && k > 0){
		if(s[i] != '0'){
			s[i] = '0';
			k--;
		}

		i++;
	}
	cout << s << endl;
}
