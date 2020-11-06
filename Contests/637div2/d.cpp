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

int n, k;
int mask[2001];
string stringNumMask[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
int numMask[10];
int ans[2001];
int dp[2001][2001];

int getInt(string s){
	int ret = 0;
	fr(i, 7){
		ret *= 2;
		if(s[i] == '1') ret++;
	}

	return ret;
}

int getOnBits(int x){
	int ret = 0;
	while(x > 0){
		if(x%2 == 1) ret++;
		x/=2;
	}

	return ret;
}

void buildDP(){
	dp[n+1][0] = 1;

	for(int i = n; i >= 1; i--){
		vector<int> add;
		fr(j, 10){
			if((numMask[j]&mask[i]) == mask[i]){
				add.pb(getOnBits(numMask[j]) - getOnBits(mask[i]));
			}
		}

		for(int j = 0; j <= k; j++){
			if(dp[i+1][j]){
				for(int y: add){
					if(y + j > k)
						continue;
					dp[i][j + y] = 1;
				}
			}
		}
	/*
		for(int y: add){
			cout << y << endl;
		}

		frr(j, k) cout << dp[i][j] << " ";
		cout << endl;*/
	}

}

void read(){
	fr(i, 10)
		numMask[i] = getInt(stringNumMask[i]);

	cin >> n >> k;

	frr(i, n){
		string s;
		cin >> s;
		mask[i] = getInt(s);
	}

	buildDP();
}

void solve(){
	for(int i = 1; i <= n; i++){	
		int deu = -1, tira = 0;

		frm(j, 10){
			if((numMask[j]&mask[i]) == mask[i]){
				tira = getOnBits(numMask[j]) - getOnBits(mask[i]);
				if(dp[i+1][k - tira]){
					deu = j;
					ans[i] = j;
					break;
				}
			}
		}

		if(deu != -1)
			k -= tira;
		else{
			cout << -1 << endl;
			exit(0);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	read();
	solve();
	frr(i, n){
		cout << ans[i];
	}
	cout << "\n";
}
