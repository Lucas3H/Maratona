#include <bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)

using coord = long double;
const long double pi = acos(-1);
const long double EPS = 1e-8;

int sign(coord x) { return (x > EPS) - (x < -EPS); }
coord sq(coord x) { return x * x; }

struct point {
	coord x, y;
	point() : x(0), y(0) {} point(coord _x, coord _y): x(_x), y(_y) {}
	inline point operator+(point& p){ return {x + p.x, y + p.y}; }
	inline point operator-(point& p){ return {x - p.x, y - p.y}; }
	inline point operator*(coord o){ return {x * o, y * o}; }
	inline point operator/(coord o){ return {x / o, y / o}; }
	inline void operator=(point& p){ x = p.x, y = p.y; }
	inline bool operator==(point& p){return sign(x - p.x) == 0 and sign(y - p.y) == 0; }

	inline coord operator*(point p){ return x * p.x + y * p.y; } // |a||b|cos(thta)
	inline coord operator^(point p){ return x * p.y - y * p.x; } // |a||b|sin(thta)

	inline int ccw(point p){ return sign(*this ^ p); } // ccw  -1 left, 0 over, 1 right

	inline long double norm(){ return hypot(x, y); }
	inline coord norm2(){ return x * x + y * y; }

  inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

struct segment {
	point a, b; // a != b
	segment() {} segment(point _a, point _b): a(_a), b(_b) {}

	bool contains(point p){ return sign((p-a)^(b-a)) == 0 and sign((p-a)*(b-a)) >= 0 and sign((p-b)*(a-b)) >= 0; }
	bool intsec(segment q){ segment p = *this;
		if (p.contains(q.a) or p.contains(q.b) or q.contains(p.a) or q.contains(p.b))
			return true;
		return p.ccw(q.a-p.a)*p.ccw(q.b-p.a) == -1 and q.ccw(p.a-q.a)*q.ccw(p.b-q.a) == -1;	
	}

	int ccw(point p){ return((b - a).ccw(p)); } // ccw  -1 left, 0 over, 1 right  of seg a->b

	coord len(){ return (a - b).norm2(); }
	coord dist(point p){
		if (sign(((p - a) * (b - a))) >= 0 and sign((p - b) * (a - b)) >= 0)
			return abs((p - a) ^ (b - a)) / (b - a).norm();
		return min((p - a).norm(), (p - b).norm());
	}
};

long double xi[2], yi[2], xf[2], yf[2];
long double vx[2], vy[2], t[2];

long double get_posX(int ind, long double t){
	return vx[ind]*t + xi[ind];
}

long double get_posY(int ind, long double t){
	return vy[ind]*t + yi[ind];
}

long double get_dist(long double t){
	return (get_posX(0, t) - get_posX(1, t))*(get_posX(0, t) - get_posX(1, t)) + (get_posY(0, t) - get_posY(1, t))*(get_posY(0, t) - get_posY(1, t));
}

int main(){
	fr(i, 2) cin >> xi[i] >> yi[i] >> xf[i] >> yf[i];

	long double sq[2];
	fr(i, 2){
		sq[i] = (xf[i] - xi[i])*(xf[i] - xi[i]) + (yf[i] - yi[i])*(yf[i] - yi[i]);
	}

	if(sq[1] < sq[0]){
		swap(xi[0], xi[1]);
		swap(yi[0], yi[1]);
		swap(xf[1], xf[0]);
		swap(yf[1], yf[0]);
    swap(sq[1], sq[0]);
	}

	long double ans = (xi[0] - xi[1])*(xi[0] - xi[1]) + (yi[0] - yi[1])*(yi[0] - yi[1]);

	if(abs(sq[0]) > 0.000000001 && abs(sq[1]) > 0.000000001){

		fr(i, 2){
			vx[i] = (xf[i] - xi[i])/(sqrt(sq[i]));
			vy[i] = (yf[i] - yi[i])/(sqrt(sq[i]));
			
			t[i] = (sqrt(sq[i]));
		}

		long double l = 0.0, r = t[0];

		while((r - l) > 0.000000001){
			long double m2 = (l + 2*r)/3;
			long double m1 = (l*2 + r)/3;

			if(get_dist(m1) < get_dist(m2)) r = m2;
			else l = m1;
		}

		//cout << l << ' ' << r << " " << get_dist(l) << " " << ans << endl;

		ans = min(get_dist((l+r)/2), ans);
	}
	
	if(abs(sq[1]) > 0.00000001){
    	vx[1] = (xf[1] - xi[1])/(sqrt(sq[1]));
		vy[1] = (yf[1] - yi[1])/(sqrt(sq[1]));
    	
		long double newy = vy[1]*t[0] + yi[1], newx = vx[1]*t[0] + xi[1];

		//cout << newx << " " << newy << " " << ans << endl;

		segment s(point(newx, newy), point(xf[1], yf[1]));
		ans = min(ans, s.dist(point(xf[0], yf[0]))*s.dist(point(xf[0], yf[0])));
	}

	printf("%.10lf\n", (double)sqrt(ans));
}
