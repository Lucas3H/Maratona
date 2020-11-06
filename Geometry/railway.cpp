// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1204 
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<double,double> pii;
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
		vetor b;

		b.x = a.x + x;
		b.y = a.y + y;

		return b;
	}

	inline vetor operator -(vetor a){
		vetor b;

		b.x = x - a.x;
		b.y = y - a.y;

		return b;
	}

	inline vetor operator *(double t){
		vetor c;
		c.x = x*t;
		c.y = y*t;

		return c;
	}

	inline vetor operator /(double t){
		vetor c;
		c.x = x/t;
		c.y = y/t;

		return c;
	}
	inline double operator ^(vetor a){
		return x*a.y - y*a.x;
	}

	inline double operator *(vetor a){
		return a.x*x + a.y*y;
	}

	inline double comp2(vetor a){ return a*a;}	

	inline double comp(vetor a){
		return sqrt(a*a);
	}

	inline double angle(vetor a, vetor b) {
		return atan2(a^b, a*b);
	}

	inline vetor makeVet(ponto a, ponto b){
		vetor c;
		c.x = b.f - a.f;
		c.y = b.s - a.s;

		return c;
	}


	inline vetor proje(vetor a, vetor b){
		return a*((a*b)/comp2(a));
	}

	inline vetor rotate (double a) { 
		vetor c;
		c.x = cos(a) * x - sin(a) * y;
		c.y = sin(a) * x + cos(a) * y;

		return c;
	}
	inline vetor rot90 () {
		vetor c;
		c.x = -y;
		c.y = x;

		return c;
	}
};


inline ponto vetorPonto(vetor a){
	ponto c;
	c.f = a.x;
	c.s = a.y;

	return c;
}

inline vetor pontoVetor(ponto a){
	vetor c;
	c.x = a.f;
	c.y = a.s;

	return c;
}

inline double comp2(vetor a){ return a*a;}

inline vetor makeVet(ponto a, ponto b){
	vetor c;
	c.x = b.f - a.f;
	c.y = b.s - a.s;

	return c;
}

inline vetor proje(vetor a, vetor b){
	return a*((a*b)/comp2(a));
}

ponto P;
double n;

ponto pt[MAXN];

double read(){
	if(!(cin >> P.f)) return 0;
	cin >> P.s;

	cin >> n;

	fr(i, n + 1) cin >> pt[i].f >> pt[i].s;

	return 1;
}

double crossProd(ponto a, ponto b, ponto c){
	double x1 = a.f - b.f, x2 = c.f - b.f;
	double y1 = a.s - b.s, y2 = c.s - b.s;

	return x1*y2 - x2*y1; 
}

double dist(ponto a, ponto b){
	return (a.f- b.f)*(a.f - b.f) + (a.s - b.s)*(a.s - b.s);
}

pii dist_line(ponto a, ponto b, ponto c){
	double d = crossProd(a, b, c);
	d*=d;

	return mp(d, dist(b, c));
}

void solve(){
	double minimo = 100000000000000.0;
	ponto pos;
	pos.f = 0.0;
	pos.s = 0.0;


	frr(i, n){	
		double d1 = dist(P, pt[i]), d2 = dist(P, pt[i-1]), d3 = dist(pt[i], pt[i-1]);
		if(d1 + d3 > d2 && d2 + d3 > d1){
			vetor v1 = makeVet(pt[i-1], P);
			vetor v2 = makeVet(pt[i-1], pt[i]);

			vetor projection = proje(v2, v1);
		/*	db;
			cout << projection.x << " " << projection.y << endl;
			cout << v1.x << " " << v1.y << " " << v2.x << " " << v2.y << endl;
		*/	projection = pontoVetor(pt[i-1]) + projection;


			if(minimo - dist(P, vetorPonto(projection)) > -eps){
				minimo = dist(P, vetorPonto(projection));
				pos = vetorPonto(projection);
			}
		}
		else{

			if(minimo - d1 > -eps){
				minimo = d1;
				pos = pt[i];
			}
			if(minimo - d2 > -eps){
				minimo = d2;
				pos = pt[i-1];
			}


		}

	}
	printf("%.4lf\n%.4lf\n", pos.f, pos.s);
}

int main(){

	while(read()){
		solve();
	}
}
