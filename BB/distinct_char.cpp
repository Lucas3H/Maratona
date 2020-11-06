// 
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

string s;
int q;

int pos, l, r, op;
char c;
int ans = 0;

set<int> fr[26];

int main(){
	cin >> s;
	int t = s.size();

	frr(i, t){
		fr[s[i-1] - 'a'].insert(i);
	}

	cin >> q;

	while(q--){
		scanf("%d", &op);

		if(op == 1){

			scanf("%d %c", &pos, &c);

			fr[s[pos-1] - 'a'].erase(pos);
			fr[c - 'a'].insert(pos);

			s[pos-1] = c;
		}
		else{
			scanf("%d %d", &l, &r);

			ans = 0;
			fr(i, 26){
				auto k = lower_bound(fr[i].begin(), fr[i].end(), l);

				if(k == fr[i].end())
					continue;

				if((*k) <= r)
					ans++;
			}

			printf("%d\n", ans);
		}
	}
}
