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

class rational{
	private:
		ll gcd(ll a, ll b){
			if(b == 0) return a;
			else return gcd(b, a%b);
		}

	public:
		ll den, num;

		rational(ll a, ll b){
			ll d = gcd(a, b);

			a /= d;
			b /= d;

			num = a;
			den = b;
		}

		void print(){
			cout << num << "/" << den << endl;
		}

		inline rational operator+(rational a){return rational(num*a.den + a.num*den, a.den*den);}
		inline rational operator-(rational a){return rational(num*a.den - a.num*den, a.den*den);}
		inline rational operator*(rational a){return rational(num*a.num, a.den*den);}
		inline rational operator/(rational a){return rational(num*a.den, a.num*den);}
		inline bool operator<(rational a){return num*a.den < a.num*den;}
		inline bool operator>(rational a){return num*a.den > a.num*den;}
		inline bool operator<=(rational a){return num*a.den <= a.num*den;}
		inline bool operator>=(rational a){return num*a.den >= a.num*den;}
		inline bool operator==(rational a){return (num == a.num && den == a.den) || (num == -a.num && den == -a.den);}
};

int main(){
	ios::sync_with_stdio(false);

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	rational x = rational(a, b);
	rational y = rational(c, d);
	
	(x + y).print();
	(x - y).print();
	(x * y).print();
	(x / y).print();
}