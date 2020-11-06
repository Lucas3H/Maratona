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

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321
#define MAXP 3

ll p[MAXP] = {MOD, MOD + 2, MOD + 30};
ll hash_indo[MAXP][MAXN], hash_volta[MAXP][MAXN];
ll power27[MAXP][MAXN];
string s;

void buildHash(){
	fr(h, MAXP){
		frr(i, s.size()){
			hash_indo[h][i] = (hash_indo[h][i-1] + power27[h][i-1]*(s[i-1] - 'a' + 1))%p[h];
		}
	}

	fr(h, MAXP){
		for(int i = s.size(); i > 0; i--){
			hash_volta[h][i] = (hash_volta[h][i+1] + power27[h][s.size() - i]*(s[i-1] - 'a' + 1))%p[h];
		}
	}
}

ll getWord1(ll l, ll r, ll h){
	l++;
	r++;
	return ((hash_indo[h][r] - hash_indo[h][l-1] + p[h])*power27[h][s.size() - l + 1])%p[h];
}

ll getWord2(ll l, ll r, ll h){
	l++;
	r++;
	return ((hash_volta[h][l] - hash_volta[h][r+1] + p[h])*power27[h][r])%p[h];
}

void print(ll l, ll r, ll greater, ll side){
	for(int i = 0; i < l; i++){
		cout << s[i];
	}

	if(side == 0){
		for(int i = l; i < l + greater; i++){
			cout << s[i];
		}
	}
	else{
		for(int i = r - greater + 1; i <= r; i++){
			cout << s[i];
		}
	}

	for(int i = r + 1; i < s.size(); i++){
		cout << s[i];
	}

	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	
	fr(h, MAXP){
		power27[h][0] = 1;
		
		frr(i, MAXN - 1){
			power27[h][i] = (power27[h][i-1]*27)%p[h];
		}
	}

	int t;
	cin >> t;

	while(t--){
		cin >> s;

		buildHash();

		ll l = 0, r = s.size() - 1;

		while(s[l] == s[r] && l < r){
			l++;
			r--;
		}

		if(l == r){
			cout << s << endl;
			continue;
		}

		ll greater = 0;
		ll side = 0;

		for(int i = l; i < r; i++){
			int deu = 1;

			fr(h, MAXP){
				if(getWord1(l, i, h) != getWord2(l, i, h)) deu = 0;
			}

			if(deu){
				greater = i - l + 1;
				side = 0;
			}
		}

		for(int i = r; i > l; i--){
			int deu = 1;

			fr(h, MAXP){
				if(getWord1(i, r, h) != getWord2(i, r, h)) deu = 0;
			}

			if(deu && (r - i + 1) > greater){
				greater = r - i + 1;
				side = 1;
			}
		}

		//cout << greater << " " << side << endl;

		print(l, r, greater, side);
	}
}
