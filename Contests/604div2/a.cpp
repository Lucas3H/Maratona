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
		char s[MAXN];
		cin >> s;

		int t = strlen(s);
		fr(i, t){
			if(s[i] == '?'){
				if(i == 0){
					s[i] = (s[i+1] + 1)%3 + 'a';
				}
				else if(i == t-1 || s[i+1] == '?'){
					s[i] = (s[i-1] + 1)%3 + 'a';
				}
				else{
					if(s[i-1] == s[i+1]){
						s[i] = (s[i-1] + 1)%3 + 'a';
					}
					else{
		//				cout << "OK" << endl;
		//				cout << (int)s[i-1] << " " << (int)s[i+1] << endl;
						s[i] = ((3 - (s[i-1] - 'a') - (s[i+1] - 'a'))%3 + 3)%3 + 'a';
					}
				}
			}

		//	cout << s << endl;
		}

		int deu = 0;
		fr(i, t-1){
			if(s[i] == s[i+1]) deu = 1;
		}
		if(!deu) cout << s << endl;
		else cout << -1 << endl;
	}
}
