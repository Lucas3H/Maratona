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

int main(){
	ios::sync_with_stdio(false);
	double l, k, t1, t2, h;
	scanf("%lf %lf %lf %lf %lf", &l, &k, &t1, &t2, &h);

	if(h < l){
		printf("%.7lf %.7lf\n", h, h);
	}
	else if(h > l){
		double b = (h + k*t1 + k*t2), a = t1, c = k*l;

		printf("%.7lf %.7lf\n", t1*(b + sqrt(b*b - 4*a*c))/(2*a), t1*(b + sqrt(b*b - 4*a*c))/(2*a));
	}
	else{
		double b = (h + k*t1 + k*t2), a = t1, c = k*l;

		printf("%.7lf %.7lf\n", h, t1*(b + sqrt(b*b - 4*a*c))/(2*a));
	
	}

}
