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

typedef basic_string<unsigned char> ustring;

int main(){
	/*unsigned char v;
	cin >> v;
	cout << (int)v << endl;
	*/
	unsigned char v[100];
	
	for(int i = 0; i < 50; i++) v[i] = 'a';

	v[0] = 195;
	v[1] = 167;

	printf("%s\n", v);

	for(int i = 0; i < 50; i++){
		cout <<(int)v[i] << " ";
	}

	scanf("%s", v);
	cout << endl;

	cout << v << endl;
	
	swap(v[1], v[3]);
	cout << v << endl;
	
}

