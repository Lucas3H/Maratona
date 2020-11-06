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

int dist2(pii a, pii b){
	return (a.f - b.f)*(a.f - b.f) + (a.s - b.s)*(a.s - b.s);
}

int main(){
	pii ini, fim, c1, c2;
	int r1, r2;

	cin >> ini.f >> ini.s >> fim.f >> fim.s >> c1.f >> c1.s >> r1 >> c2.f >> c2.s >> r2;

	double ans = 0.0;
	int d1 =dist2(ini, c2);
	int d2 = dist2(fim, c2);

	ans += sqrt(d1 - r2*r2);
	ans += sqrt(d2 - r2*r2);

	double ang = acos((d1 + d2 - dist2(ini, fim))/(2*sqrt(d1)*sqrt(d2)));
	ang -= acos(r2/sqrt(d1));
	ang -= acos(r2/sqrt(d2));

	/*
	cout << acos(r2/sqrt(d2)) << " " << acos(r2/sqrt(d1)) << endl;

	cout << r2 << " " << acos((double)17/25) << endl;
	*/
	//cout << ans << endl;

	ans += (double)r2*(ang);

	printf("%.8lf\n", ans);
}
