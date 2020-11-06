// https://www.urionlinejudge.com.br/judge/pt/problems/view/2072
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

struct pt{
	int x, y, z;
};

struct vetor{
	int x, y, z;
};

struct plane{
	vetor n;
	int d;
};

pt p[100];
int n;

vetor cross(vetor a, vetor b){
	vetor ret;

	ret.x = a.y*b.z - a.z*b.y;
	ret.y = a.z*b.x - a.x*b.z;
	ret.z = a.x*b.y - a.y*b.x;
	
	return ret;
}

vetor makeVetor(pt a, pt b){
	vetor ret;
	ret.x = b.x - a.x;
	ret.y = b.y - a.y;
	ret.z = b.z - a.z;

	return ret;
}

int dotProduct(vetor a, pt b){
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

int check(plane a){
	int ans = 0;
	fr(i, n){
		if(dotProduct(a.n, p[i]) == a.d) ans++;
	}

	return ans;
}

bool comp(pt a, pt b){
	if(a.x == b.x && a.y == b.y && a.z == b.z) return 1;
	else return 0;
}

void read(){
	cin >> n;
	fr(i, n) cin >> p[i].x >> p[i].y >> p[i].z;
}

vetor perpendicular(vetor a){
	vetor ret;
	if(a.x != 0){
		ret.y = a.x;
		ret.z = a.x;
		ret.x = - a.y - a.z;
	}

	else if(a.y != 0){
		ret.y = -a.x - a.z;
		ret.z = a.y;
		ret.x = a.y;
	}

	else{
		ret.y = a.z;
		ret.z = -a.x - a.y;
		ret.x = a.z;
	}

	return ret;
}

void solve(){
	int ans = 0;

	if(n == 1){
		cout << 1 << endl;
		return;
	}
	else if(n == 2){
		cout << 2 << endl;
		return;
	}

	fr(i, n){
		fr(j, i){
			fr(k, j){
				plane a;
				vetor v1 = makeVetor(p[i], p[j]), v2 = makeVetor(p[i], p[k]);

				a.n = cross(v1, v2);

				if(comp(p[i], p[j]) && comp(p[i], p[k])){
					a.n.x = 1;
					a.n.y = 1;
					a.n.z = 1;
				}
				else if(a.n.x == 0 && a.n.y == 0 && a.n.z == 0){
					if(v1.x == 0 && v1.y == 0 && v1.z == 0) a.n = perpendicular(v2);
					else a.n = perpendicular(v1);
				}

				a.d = dotProduct(a.n, p[i]);

				ans = max(ans, check(a));
			}
		}
	}

	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;

	while(t--){
		read();
		solve();
	}
}
