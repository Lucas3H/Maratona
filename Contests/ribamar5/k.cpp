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

int m[65][2100];
int a[65];
int n, g;
	
void read(){
	cin >> n >> g;
	frr(i, n){
		cin >> a[i];
	}
}

void build(int l){
	if(l > n) return;
	frm(i, n + 1){
		frm(j, 2000){
			if(a[l] + j <= 2000){
				m[i+1][a[l] + j] += m[i][j];
			}
		}
	}

	build(l + 1);
}

int main(){
	m[0][0] = 1;
	read();
	build(1);

	pii ans = {-1, 1};

/*
	fr(i, n + 1){
		fr(j, g + 10){
			cout << m[i][j] <<" ";
		}

		cout << "\n";
	}
*/

  /*
  x = (10 - g + j)/(i+1)
  */
  
	int apareceu = 0;

	frr(i, n){
		frr(j, 2000){
			if(m[i][j] > 0 && j >= g - 10 && (-g + j + 10) <= 5*(i+1)){
				if(ans.f*(i+1) < (-g + j + 10)*ans.s){
					ans = {-g + j + 10, i+1};
				}
			}
		}
	}

	if(ans.f >= 0) printf("%.8lf\n", (double)ans.f/ans.s);
	else printf("impossible\n");
}
