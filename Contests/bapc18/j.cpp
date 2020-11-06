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
typedef pair<ll, ll> pll;
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
#define pi acos(-1)

double l[4];
double heron(double a, double b, double c){
	if(c > a + b || a > b + c || b > a + c) {
		return -INF;
	}
	return sqrt((a + b + c)/2*(a + b - c)/2*(c + b - a)/2*(a + c - b)/2);
}

double maximo(double a, double b){
	if(a > b) return a;
	else return b;
}

double solve(){
	double ang = 0.000000, eps = 0.000001, ans = 0.000000;
	double a = l[3], b = l[2];
	double diag = a - b;

	while(ang <= pi/2){
		diag = sqrt(a*a + b*b - 2*a*b*cos(ang));
		double area = a*b*sin(ang)/2 + heron(l[1], l[0], diag);

		//printf("%.6lf\n", diag);

		
		ans = maximo(area, ans);
		ang+=eps;
	}

	a = l[3], b = l[1];
	ang = 0.0000000, diag = a - b;

	while(ang <= pi/2){
		diag = sqrt(a*a + b*b - 2*a*b*cos(ang));
		double area = a*b*sin(ang)/2 + heron(l[2], l[0], diag);

		ans = maximo(area, ans);
		ang+=eps;
	}

	a = l[3], b = l[0];
	ang = 0.0000000, diag = a - b;

	while(ang <= pi/2){
		diag = sqrt(a*a + b*b - 2*a*b*cos(ang));
		double area = a*b*sin(ang)/2 + heron(l[1], l[2], diag);

		ans = maximo(area, ans);
		ang+=eps;
	}

	return ans;
}

int main(){
	//ios::sync_with_stdio(false);
	cin >> l[0] >> l[1] >> l[2] >> l[3];
	sort(l, l + 4);

	printf("%.7lf\n", solve());
}
