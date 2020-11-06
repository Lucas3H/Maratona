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

int main(){
		ios::sync_with_stdio(false);

		string s;
		int t;
		cin >> t;

		int x = 0, y = 0;

		while(t--){
			int xmin = 0, xmax = 0, ymin = 0, ymax = 0;
			cin >> s;
			x = 0;
			y = 0;

			int m1x = 0, m2x = 0;
			int m1y = 0, m2y = 0;

			fr(i, s.size()){
				if(s[i] == 'A') x--;
				else if(s[i] == 'S') y--;
				else if(s[i] == 'W') y++;
				else x++;


				xmin = min(xmin, x);
				xmax = max(xmax, x);

				ymin = min(ymin, y);
				ymax = max(ymax, y);


				int X = max(x - xmin, xmax - x);
				int Y = max(y - ymin, ymax - y);

				if((s[i] == 'A' || s[i] == 'D') && m2x < X){
						if(m1x < X) m1x = X;
						else m2x = X;
				}

				if((s[i] == 'S' || s[i] == 'W') && m2y < Y){
						if(m1y < Y) m1y = Y;
						else m2y = Y;
				}
			}

			int a;
			if(m1x <= 1) a = m1x;
			else a = max(m1x - 1, m2x);


			int b;
			if(m1y <= 1) b = m1y;
			else b = max(m1y - 1, m2y);

			//cout << m1y << " " << m2y << endl;
			//cout << m1x << " " << m2x << endl;

			cout << min((a+1)*(m1y + 1), (b+1)*(m1x + 1)) << endl;
		}
}
