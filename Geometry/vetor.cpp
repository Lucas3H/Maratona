// teste
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

#define eps 0.0000000001

struct vetor{

	double x, y;

	inline vetor operator +(vetor a){ 
		return {x + a.x, y + a.y}; 
	}

	inline vetor operator -(vetor a){
		return {x - a.x, y - a.y};
	}

	inline vetor operator *(double t){
		return {x*t, y*t};
	}

	inline vetor operator /(double t){
		return {x/t, y/t};
	}
	inline double operator ^(vetor a){
		return x*a.y - y*a.x;
	}

	inline double operator *(vetor a){
		return a.x*x + a.y*y;
	}

	inline double comp2(){
		return (*this)*(*this);
	}

	inline double comp(){
		return sqrt((*this)*(*this));
	}

	inline double dist2(vetor a){
		return (a - (*this)).comp2();
	}

	inline double dist(vetor a){
		return sqrt((a - (*this)).comp2());
	}

	inline double angle(vetor a) {
		return atan2((*this)^a, (*this)*a);
	}

	inline vetor proje(vetor a){
		return a*((a*(*this))/a.comp2());
	}

	inline vetor rotate (double a) { 
		return {cos(a)*x - sin(a)*y, sin(a)*x + cos(a)*y};
	}

	inline vetor rot90 () {
		return {y, -x};
	}

	// this is to the (1 left, 0 over, -1 right) of a
	inline int lor(vetor a) {
		return (eps < ((*this)^a)) - (((*this)^a) < -eps);
	}

	double dist_line(vetor a, vetor b){
		return (*this)^(b - a)/a.dist(b);
	}
};

struct CartesianPlane{

	inline ponto vetorPonto(vetor a){
		return mp(a.x, a.y);
	}

	inline vetor pontoVetor(ponto a){
		return {a.f, a.s};
	}

	inline vetor makeVetor(ponto a, ponto b){
		return {b.f - a.f, b.s - a.s};
	}
};


int main(){
	ios::sync_with_stdio(false);
	vetor a, b;
	cin >> a.x >> a.y >> b.x >> b.y;

	vetor c = a.rot90();
	cout << c.x << " " << c.y << endl;
	cout << c.comp2() << endl;
}
