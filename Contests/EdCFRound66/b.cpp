#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

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

int fr[101];
stack<int> a;

int main(){
		ios::sync_with_stdio(false);
		int l;
		cin >> l;
		ll x = 0;
		string s;

		ll t = 1;
		fr(i, 32)t*=2;
		t--;

		int ruim = 0;
		fr(i, l+1){
				getline(cin, s);
				if(ruim) continue;
		//		cout << s << endl;

				if(s[0] == 'f'){
					int n;
					if(s.size() == 7){
						n = 100*(s[4] - '0') + 10*(s[5] - '0') + s[6] - '0';
					}
					else if(s.size() == 6){
						n = 10*(s[4] - '0') + s[5] - '0';
					}
					else n = s[4] - '0';

					fr[n]++;
					a.push(n);
				}
				else if(s[0] == 'e'){
					fr[a.top()]--;
					a.pop();
				}
				else if(s[0] == 'a'){
					ll k = 1;

					for(int i = 2; i <=100; i++){
						if(log(t) < (fr[i])*log(i)){
							ruim = 1;
							continue;
						};

						k *= pow(i, fr[i]);

						if(k > t){
							ruim = 1;
							continue;
						}
					}

					x += k;

					if(x > t){
						ruim = 1;
					}
				}
		}

		if(ruim){
				cout << "OVERFLOW!!!" << endl;
				return 0;
		}

		cout << x << endl;
		return 0;
}
