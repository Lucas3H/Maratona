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

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

int v[3][MAXN];
int bit[3][MAXN];
int n;

void update(int i, int val, int t){
 //   cout << i << " OLA  " << n << endl;
	while(i <= n){

        if(t == 0) {
			bit[t][i] += val;
		}
		else if(t == 1) bit[t][i] = min(bit[t][i], val);
		else bit[t][i] = max(bit[t][i], val);

		i += i & (-i);
    }
}

int query(int i, int t){
    int sum = 0;

	if(t == 1) sum = MAXN;

    while(i > 0){
		if(t == 0) sum += bit[t][i];
		else if(t == 1) sum = min(bit[t][i], sum);
		else sum = max(bit[t][i], sum);

        i -= i & (-i);
    }

    return sum;
}

int abertos = 0, fechados = 0;

int main(){
	ios::sync_with_stdio(false);

	cin >> n;

	string s;
	cin >> s;

	int st = s.size();
	int cursor = 1;

	int ans = 0;
	//cout << query(1, 0) << " BIT " << bit[0][1] << endl;

	fr(i, st){
		if(s[i] == 'R') cursor++;
		else if(s[i] == 'L') cursor--;
		else if(s[i] >= 'a' && s[i] <= 'z'){
			if(v[0][cursor] == 1) abertos--;
			if(v[0][cursor] == -1) fechados--;
			
			update(cursor, 0 - v[0][cursor], 0);
			v[0][cursor] = 0;

			int atu = query(cursor, 0);

			update(cursor, atu - v[1][cursor], 1);
			v[1][cursor] = atu;

			update(cursor, atu - v[2][cursor], 2);
			v[2][cursor] = atu;
		}
		else if(s[i] == '('){
			abertos++;
			if(v[0][cursor] == -1) fechados--;

			update(cursor, 1 - v[0][cursor], 0);
			v[0][cursor] = 1;

			int atu = query(cursor, 0);
		//	cout << "atu " << atu << endl;

			update(cursor, atu - v[1][cursor], 1);
			v[1][cursor] = atu;

			update(cursor, atu - v[2][cursor], 2);
			v[2][cursor] = atu;
		}
		else{
			fechados++;
			if(v[0][cursor] == 1) abertos--;

			update(cursor, - 1 - v[0][cursor], 0);
			v[0][cursor] = -1;

			int atu = query(cursor, 0);

			update(cursor, atu - v[1][cursor], 1);
			v[1][cursor] = atu;

			update(cursor, atu - v[2][cursor], 2);
			v[2][cursor] = atu;	
		}

		//cout << query(cursor, 0) << " " << query(cursor, 1) << " " << query(cursor, 2) <<" " << endl;

		//cout << v[2][2] << " ";

		if(abertos == fechados && query(n, 1) == 0) cout << query(n, 2) << " ";
		else cout << -1 << " ";
		//cout << endl;
	}

	cout << endl;
}
