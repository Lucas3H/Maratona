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

    int k;
    cin >> k;

    while(k--){
        int n;
        cin >> n;

		string s, t;
		cin >> s >> t;

		vector<char> dif1, dif2;
        fr(i, n){
			if(s[i] != t[i]){
				dif1.pb(s[i]);
				dif2.pb(t[i]);
			}
        }

		if(dif1.size() > 2){
			cout << "No" << endl;
			continue;
		}

		sort(dif1.begin(), dif1.end());
		sort(dif2.begin(), dif2.end());

		if(dif1[0] != dif1[1] || dif2[0] != dif2[1]){
			cout << "No" << endl;
		}
		else cout << "Yes" << endl;
    }
}
