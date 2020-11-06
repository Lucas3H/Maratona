#include<bits/stdc++.h>
 
using namespace std;
 
#define fr(i, n) for(__int128 i = 0; i < n; i++)
#define frr(i, n) for(__int128 i = 1; i <= n; i++)
#define frm(i, n) for(__int128 i = n-1; i >= 0; i--)
 
#define pb push_back
#define f first
#define s second
 
#define ll long long
typedef pair<ll,ll> pii;
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
 
__int128 f1(__int128 k,__int128 a, __int128 b){
	//cout << k << " " <<a << endl;
	__int128 ret = 0;
	frr(i, k){
		ret += i*(a/i - b/i);
	}
 
	return ret;
}
 
__int128 f2(__int128 k, __int128 a, __int128 b){
	__int128 ret = (__int128)0;
	__int128 x0, x1;
	frr(i, k){
		if(b/i >= k){
			x0 = b/i;
			x1 = max(b/(i+1), k);
			ret -= (i)*(x0 - x1)*(x0 + x1 + 1)/2;
		}
		//cout << ret << endl;
		if(a/i >= k){
			x0 = a/i;			
			x1 = max(a/(i+1), k);
			ret += (i)*(x0 - x1)*(x0 + x1 + 1)/2;
		}
		//cout << (__int128)ret << " " << (__int128)x0 << ' ' << (__int128)x1 << endl;
		//cout << (__int128)ret << endl;
	}
 
	return ret;
}
 
__int128 solve(__int128 a, __int128 b){
	__int128 ret = 0;
	__int128 s = sqrt((ll)a);
	//s = a/s;
 
	if(s < 5){
		return f1(a, a, b);
	}
	else{
		//cout << f2(s - 1, a, b) << endl;
		//cout << f1(s, a, b) << endl;
		//cout << (__int128)f2(s-a, a) << endl;
		//
		/*
		cout << s << endl;
		cout << f1(s, a ,b) << endl;
		cout << f2(s, a ,b) << endl;
		*/
		//cout << f2()
 
		//cout << f1(s, a, b) + f2(s, a, b) << " " << f1(a, a, b) << endl;
		//return (f1(s, a, b) + f2(s, a, b));
		return (f1(s, a, b) + f2(s, a, b));
		
		//return (f1(s, a, b) + f2(s, a, b));
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	
	ll a, b;

	srand(10);
/*
	frr(i, 10000){
		a = rand()%MOD;
		b = rand()%MOD;

		if(b < a) swap(a, b); 

		if(solve(b, a - 1) == 0) cout << a << " " << b << endl;
	}
	db;
	*/
	cin >> a >> b;
 
	__int128 ans = (__int128)(solve((__int128)b, a-(__int128)1));
 
	cout << (ll)ans << endl;
	
}