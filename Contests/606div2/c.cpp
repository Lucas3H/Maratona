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

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;

		if(s.size() <= 2){
			cout << 0 << endl << endl;
			continue;
		}

		set<int> pos;
		fr(i, s.size()-2){
			if(s[i] == 'o' && s[i + 1] == 'n' && s[i+2] == 'e') {
				if( i-1 >= 0 && s[i-1] == 'o') pos.insert(i + 2);
				else pos.insert(i + 1);
			}
			else if(s[i] == 't' && s[i + 1] == 'w' && s[i+2] == 'o'){
				if(i + 3 < s.size() && s[i+3] == 'o') pos.insert(i + 2);
				else pos.insert(i + 3);
			}
		}

		cout << pos.size() << endl;
		for(auto x: pos){
			cout << x <<  " ";
		}

		cout << endl;
	}
}
