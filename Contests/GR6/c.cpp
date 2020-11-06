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

int r, c;
int m[600][600];
int rows_gcd[MAXN], columns_gcd[MAXN];

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b , a%b);
}

int lcm(int a, int b){
	return (a*b)/gcd(a, b);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> r >> c;

	if(r == 1 && c == 1){
		cout << 0 << endl;
		return 0;
	}
	else if(r == 1){
		frr(i, c){
			cout << i + 1 << " ";
		}
		cout << endl;

		return 0;
	}
	else if(c == 1){
		frr(i, r){
			cout << i+1 << endl;
		}

		return 0;
	}

	m[1][1] = 4;
	m[1][2] = 12;
	m[2][1] = 2;
	m[2][2] = 9;

	rows_gcd[1] = 4;
	rows_gcd[2] = 1;
	columns_gcd[1] = 2;
	columns_gcd[2] = 3;


	int val = 5;
	
	for(int i = 3; i <= c; i++){
		m[1][i] = lcm(val, rows_gcd[1]);
		m[2][i] = val;
		columns_gcd[i] = val++;
	}

	for(int i = 3; i <= r; i++){
		for(int j = 1; j <= c; j++){
			m[i][j] = lcm(val, columns_gcd[j]);
		}
		rows_gcd[i] = val++;
	}

	frr(i, r){
		frr(j, c){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
