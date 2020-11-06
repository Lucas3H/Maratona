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
	inline int side(vetor a) {
		return (eps < ((*this)^a)) - (((*this)^a) < -eps);
	}

	double dist_line(vetor a, vetor b){
		return (*this)^(b - a)/a.dist(b);
	}
	
	inline bool cmp(vetor a, vetor b) {
    	return a.x < b.x || (a.x == b.x && a.y < b.y);
	}

	/*clock_wise*/
	inline bool cw(vetor a, vetor b, vetor c) {
    	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
	}

	/*counter_clock_wise*/
	inline bool ccw(vetor a, vetor b, vetor c) {
    	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
	}

};

struct vetor3D{
	double x, y, z

	inline vetor operator +(vetor a){ 
		return {x + a.x, y + a.y, z + a.z}; 
	}

	inline vetor operator -(vetor a){
		return {x - a.x, y - a.y, z - a.z};
	}

	inline vetor operator *(double t){
		return {x*t, y*t, z*t};
	}

	inline vetor operator /(double t){
		return {x/t, y/t, z/t};
	}

	inline vetor operator ^(vetor a){
		return {y*a.z - z*a.y, z*a.x - x*a.y, x*a.y - y*a.x}
	}

	inline double operator *(vetor a){
		return a.x*x + a.y*y + a.z*z;
	}

	inline double comp2(){
		return (*this)*(*this);
	}

	inline double comp(){
		return sqrt(comp2());
	}

	inline double dist2(vetor a){
		return (a - (*this)).comp2();
	}

	inline double dist(vetor a){
		return sqrt((a - (*this)).comp2());
	}

	inline double angle(vetor a) {
		return atan2(((*this)^a).comp(), (*this)*a);
	}

	inline vetor proje(vetor a){
		return a*((a*(*this))/a.comp2());
	}

	double dist_line(vetor a, vetor b){
		return (*this)^(b - a)/a.dist(b);
	}
};

struct plane{
	vetor3D n;
	double d;

	plane makePlane(vetor3D a, vetor3D b){
		plane P;
		P.n = (a - (*this))^(b - (*this));
		P.d = P.n*a;
	}
};

struct circle{
	vetor c;
	double r;

	inline int is_inside(vetor a){
		return (r - a.dist(c) > -eps);
	}
};

circle find_circle(vetor a, vetor b, vetor c){
	circle o;
	o.c.y = -((a.x*a.x - c.x*c.x)*(a.x - b.x) + (a.y*a.y - c.y*c.y)*(a.x - b.x) + (b.x*b.x - a.x*a.x)*(a.x - c.x) + (b.y*b.y - a.y*a.y)*(a.x - c.x))/((c.y - a.y)*(a.x - b.x) - (b.y - a.y)*(a.x - c.x))/2;
	o.c.x = -((a.x*a.x - c.x*c.x)*(a.y - b.y) + (a.y*a.y - c.y*c.y)*(a.y - b.y) + (b.x*b.x - a.x*a.x)*(a.y - c.y) + (b.y*b.y - a.y*a.y)*(a.y - c.y))/((c.x - a.x)*(a.y - b.y) - (b.x - a.x)*(a.y - c.y))/2;

	o.r = o.c.dist(a);

	return o;
}
