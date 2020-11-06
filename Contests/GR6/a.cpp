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

void func(string s){
	int sum = 0, even = 0, zero = 0;

	fr(i, s.size()){
		sum +=  (s[i] - '0');
		if(s[i] == '0') zero++;
		else if((s[i] - '0')%2 == 0) even = 1;
	}

	//cout << sum << ' ' << zero << " " << even << endl;

	if(sum%3 == 0 && zero > 0 && (zero + even) > 1){
		cout << "red\n";
	}	
	else cout << "cyan\n";
}

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	while(n--){
		string s;
		cin >> s;

		func(s);
	}
}
